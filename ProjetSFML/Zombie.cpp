#include "Zombie.h"
#include "Fighter.h"

Zombie::Zombie()
{
}

void Zombie::init(IAssetManager* assetManager)
{
	GameObject::init(assetManager, ZOMBIE_NORMAL_TEXTURE_NAME, FILE_PATH_ZOMBIE_NORMAL);
	GameMovingObject::init(assetManager, SOUND_NAME_ZOMBIE_DEATH, FILE_PATH_ZOMBIE_DEATH);
	assetManager->loadTexture(ZOMBIE_SUPER_SAYAN_TEXTURE_NAME, FILE_PATH_ZOMBIE_SUPER_SAYAN);
	//On sauvegarde la seconde texture
	normalTexture = getTexture(); // J'assume que la texture "normale" est celle qui est généré dans le init du GameObject. Donc je fait directement un getTexture()
	superTexture = &assetManager->getTexture(ZOMBIE_SUPER_SAYAN_TEXTURE_NAME);
	radius = getTexture()->getSize().x / 2.0f;
	setSpeed(SPEED_INITIAL_VALUE);
	setOrigin(radius, radius);
	setLimits(Game::WORLD_WIDTH, Game::WORLD_HEIGHT);
}

void Zombie::moveToWithinLimits(const sf::Vector2f& offset)
{
	//Je vais aussi gérer l'affichage de la rotation
	float angle = atanf(offset.y/offset.x) * RADS_TO_ANGLE;
	if (offset.x<0) angle += 180; //Ils ont un probleme de rotation quand la direction x est negative. 
	setRotation(angle);

	move(offset.x, offset.y);

	if (getPosition().x > limits.maxX || getPosition().x < limits.minX) {
		move(-offset.x, 0);
		reverseDirectionOnX();
	}
	if (getPosition().y > limits.maxY || getPosition().y < limits.minY) {
		move(0, -offset.y);
		reverseDirectionOnY();
	}
}

void Zombie::deactivate()
{
	sound.play();
}

void Zombie::update()
{
	if (isSuperSayan) {
		setSpeed(SPEED_INITIAL_VALUE);
		setTexture(*normalTexture);
	}
	else {
		setSpeed(getSpeed()* SUPER_SPEED_MULTIPLIER);
		setTexture(*superTexture);
	}
	isSuperSayan = !isSuperSayan;
}

void Zombie::notify(Subject* subject)
{
	if (typeid(*subject) == typeid(Fighter))
	{
		Fighter* fighter = static_cast<Fighter*>(subject);
		if (fighter->isActive())
		{
			setDestination(fighter->getPosition());
		}
		else 
		{
			float angle = ((float)(rand() % 100)) / 100.0f; //Valeur de 0 à 1
			initDirectionOnXAndY(angle * M_PI * 2.0f);
		}
	}
}
