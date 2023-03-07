#define _USE_MATH_DEFINES
#include "Game.h"      

Game::Game(IPlayerControlsBridge* playerControlsBridge, RenderWindow* renderWindow, IAssetManager* assetManager, IHud* hud, GameObject* background, GameMovingObject* fighter, GameMovingObject** zombies, GameMovingObject** projectiles, GameObject** lives)
{
	this->playerControlsBridge = playerControlsBridge; 
	this->mainWin = renderWindow;
	this->assetManager = assetManager;
	this-> hud = hud; 
	this->fighter = fighter; 
	this->zombies = zombies;
	this->background = background;
	this->projectiles = projectiles;
	this->lives = lives;
	numberOfFrames = 0;
	nbSeconds = Timer::GAME_TIME_IN_SECONDES;
	nbLives = LivesCounter::NB_LIVES_ON_START;
	gameOver = false;

	mainWin->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "The Legend of Praxis: Zombie Attack & Knuckles 2");

	//Synchonisation coordonnée à l'écran. Normalement 60 frames par secondes. 
	mainWin->setFramerateLimit(NB_FPS);
}
/// <summary>
/// En gros cette méthode permet de donner une position aléatoire selon l'objet. Peut être pour un potentiel spawn de zombie ¯\_(OuO)_/¯
/// </summary>
/// <param name="object">L'objet de type GameMovingObject pour avoir le radius</param>
/// <returns>Une position aléatoire qui respecte le monde</returns>
sf::Vector2f Game::getRandomPosition(GameObject* object)
{
	float halfTexture =object->getTexture()->getSize().x / 2;
	sf::Vector2f newPosition = sf::Vector2f(WORLD_WIDTH * (((float)(rand() % 100)) / 100.0f),
		WORLD_HEIGHT * (((float)(rand() % 100)) / 100.0f)); //Nouvelle position aléatoire

	if (newPosition.x < halfTexture) newPosition.x = halfTexture; //Réajustement des limites.
	if (newPosition.y < halfTexture) newPosition.y = halfTexture;
	if (newPosition.x + halfTexture > WORLD_WIDTH) newPosition.x = WORLD_WIDTH - (halfTexture + 1);
	if (newPosition.y + halfTexture > WORLD_HEIGHT) newPosition.y = WORLD_HEIGHT - (halfTexture + 1);
	return newPosition;
}
void Game::init()
{
	srand(time(NULL));

	//BGM Je sais que c'est pas game qui gère les son. Mais vu que c'est une musique. C'est général. Et il n'y a aucune classe qui serait apte à gérer de la musique
	assetManager->loadSound(NAME_MUSIC, FILE_PATH_MUSIC);
	sound.setBuffer(assetManager->getSound(NAME_MUSIC));
	sound.play();

	background->init(assetManager);
	fighter->init(assetManager);
	fighter->activate(CENTER);

	for (int i = 0; i < Projectile::NB_PROJECTILES; i++) {
		projectiles[i]->init(assetManager);
	}

	for (int i = 0; i < Zombie::NB_ZOMBIE; i++) 
	{
		zombies[i]->init(assetManager);
		zombies[i]->activate(getRandomPosition(zombies[i]));
		IObserver* zombie = static_cast<IObserver*>(zombies[i]);
		fighter->registerObserver(zombie);
	}

	for (int i = 0; i < Life::NB_LIVES; i++) {
		lives[i]->init(assetManager);
		lives[i]->activate(getRandomPosition(lives[i]));
	}

	hud->init(assetManager, SCREEN_WIDTH, SCREEN_HEIGHT, WORLD_WIDTH, WORLD_HEIGHT);


}
void Game::run()
{
	init();
	sf::Vector2f fighterOffset;
	while (mainWin->isOpen())
	{
		manageEvents();
		if (!gameOver)
		{
			if (nbLives > 0) {
				fighterOffset = manageGameInputs();
				manageFighterMovements(fighterOffset);
			}
			manageZombiesMovements();
			manageProjectilesMovements();
			manageView();
		}
		draw();		
	}
}
void Game::manageEvents()
{
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
	while (mainWin->pollEvent(event))
	{
		//x sur la fenêtre
		if (event.type == sf::Event::Closed)
		{
			mainWin->close();
		}
	}
	//Techniquement c'est un event
	if (numberOfFrames % NB_FPS == 0)
	{
		if (nbSeconds == 0) {
			gameOver = true;
		}
	}
}
sf::Vector2f Game::manageGameInputs()
{
	float rotationAngleInRadians = playerControlsBridge->getRotationRadianAngle();
	sf::Vector2f fighterOffset = playerControlsBridge->getOffset(fighter->getSpeed());

	fighter->saveRotationRadianAngle(rotationAngleInRadians); //On sauvegarde l'angle mais on ne rotationne pas tout de suite.
	if (fighter->isActive())
	{
		if (playerControlsBridge->playerFired())
		{
			if (hasAlreadyShot)
			{
				for (int i = 0; i < Projectile::NB_PROJECTILES; i++)
				{

					if (!projectiles[i]->isActive()) {
						projectiles[i]->initDirectionOnXAndY(rotationAngleInRadians);
						projectiles[i]->activate(fighter->getPosition());
						break;
					}
				}
			}
			hasAlreadyShot = !hasAlreadyShot;
		}
	}
	return fighterOffset;
}
void Game::manageFighterMovements(const sf::Vector2f &offset)
{
	if (fighter->isActive()) {
		fighter->setRotation(fighter->getSavedRotationRadianAngle() * RADS_TO_ANGLE);
		fighter->moveToWithinLimits(offset);
		for (int i = 0; i < Zombie::NB_ZOMBIE; i++)
		{
			if (fighter->testCollisionCircles(*zombies[i])) {
				fighter->update();
				nbLives--;
				hud->getLivesCounter()->update();
			}
		}
		for (int i = 0; i < Life::NB_LIVES; i++)
		{
			if (lives[i]->isActive()) {
				if(fighter->testCollisionCircles(*lives[i]))
				{
					nbLives = LivesCounter::NB_LIVES_ON_START;
					lives[i]->deactivate();
					hud->getLivesCounter()->init(assetManager);
				}
			}
		}
	}
	else {
		fighter->update();
	}
}
void Game::manageZombiesMovements()
{
	for (int i = 0; i < Zombie::NB_ZOMBIE; i++)
	{
		sf::Vector2f offset= zombies[i]->getOffset();
		zombies[i]->moveToWithinLimits(offset);
		float angleRad = zombies[i]->getSavedRotationRadianAngle();
	}
}
void Game::manageProjectilesMovements()
{
	for (int i = 0; i < Projectile::NB_PROJECTILES; i++)
	{
		if (projectiles[i]->isActive()) {
			projectiles[i]->moveToWithinLimits(projectiles[i]->getOffset());
			projectiles[i]->update();
			//J'aime pas les boucles imbriqué en jeux vidéo. J'ai l'impression de briser l'opti de mon jeu.
			for (int y = 0; y < Zombie::NB_ZOMBIE; y++)
			{
				if(zombies[y]->isActive())//Pour éviter que plusieurs balles touchent le même zombie et brise le score
				{
					if (projectiles[i]->testCollisionBoxes(*zombies[y])) {
						projectiles[i]->deactivate();
						zombies[y]->deactivate();
						zombies[y]->activate(getRandomPosition(zombies[y]));
						zombies[y]->update();
						hud->getScore()->update();
					}
				}
			}
		}
	}
}
void Game::manageView()
{
	hud->update(fighter->getPosition());
	numberOfFrames++;
	if (numberOfFrames % NB_FPS==0)
	{
		hud->getTimer()->update();
		nbSeconds--;

	}
}
void Game::draw()
{
	mainWin->clear();
	mainWin->draw(*background);
	mainWin->draw(*fighter);
	hud->draw(*mainWin);
	for (int i = 0; i < Projectile::NB_PROJECTILES; i++)
	{
		if (projectiles[i]->isActive()) {
			mainWin->draw(*projectiles[i]);
		}
	}

	for (int i = 0; i < Zombie::NB_ZOMBIE; i++)
	{
		mainWin->draw(*zombies[i]);
	}

	for (int i = 0; i < Life::NB_LIVES; i++)
	{
		if (lives[i]->isActive()) {
			mainWin->draw(*lives[i]);
		}
	}

	mainWin->display();

}
