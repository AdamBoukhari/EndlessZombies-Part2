#include "Fighter.h"
#include "Game.h"

Fighter::Fighter()
{
}
void Fighter::init(IAssetManager* assetManager)
{
	//load
	assetManager->loadTexture(TEXTURE_NAME_FIGHGTER_DEAD, FILE_PATH_FIGHTER_DEAD);
	//initialisation
	GameObject::init(assetManager, TEXTURE_NAME_ALIVE, FILE_PATH_ALIVE);
	GameMovingObject::init(assetManager, SOUND_NAME_FIGHTER_DEATH, FILE_PATH_FIGHTER_DEATH);
	//Récupération des assets
	normalTexture = getTexture();  // J'assume que la texture "normale" est celle qui est généré dans le init du GameObject. Donc je fait directement un getTexture()
	deadTexture = &assetManager->getTexture(TEXTURE_NAME_FIGHGTER_DEAD);
	//Initialisations des valeurs
	setSpeed(SPEED_INITIAL_VALUE);
	setOrigin(getTexture()->getSize().x / 2.0f, getTexture()->getSize().y / 2.0f);
	setLimits(Game::WORLD_WIDTH, Game::WORLD_HEIGHT);

}

void Fighter::moveToWithinLimits(const sf::Vector2f& offset)
{
	//Déplacement du joureur
	move(offset.x, offset.y);

	if (getPosition().x > limits.maxX || getPosition().x < limits.minX) {
		move(-offset.x, 0);
	}
	if (getPosition().y > limits.maxY || getPosition().y < limits.minY) {
		move(0, -offset.y);
	}

	notifyObservers();
}

void Fighter::activate(sf::Vector2f position)
{
	GameMovingObject::activate(position);
	notifyObservers();
}

void Fighter::deactivate()
{
	sound.play();
	GameMovingObject::deactivate();
	notifyObservers();
}

void Fighter::update()
{
	if (isActive()) {
		deactivate();
		setTexture(*deadTexture);
	}
	else {
		nbFrameDead++;
		if (nbFrameDead >= Game::NB_FPS * NB_SECONDS_DEAD) {
			activate(getPosition());
			setTexture(*normalTexture);
			nbFrameDead = 0;
		}
	}

}
