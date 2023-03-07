#include "Projectile.h"

Projectile::Projectile()
{
}

void Projectile::init(IAssetManager* assetManager)
{
	//Load
	assetManager->loadSound(GUNSHOT_NAME, GUNSHOT_FILENAME);
	//Initialisation
	GameObject::init(assetManager, TEXTURE_NAME, FILE_PATH);
	GameMovingObject::init(assetManager, GUNSHOT_NAME, GUNSHOT_FILENAME);
	gunshotSound.setBuffer(assetManager->getSound(GUNSHOT_NAME));
	radius = getTexture()->getSize().x / 2.0f;
	setSpeed(SPEED);
	setOrigin(radius, radius);
	setLimits(Game::WORLD_WIDTH, Game::WORLD_HEIGHT);
}

void Projectile::moveToWithinLimits(const sf::Vector2f& offset)
{
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

void Projectile::update()
{
	lifetime++;

	if (lifetime >= Game::NB_FPS * NB_SECONDS) {
		lifetime = 0;
		deactivate();
	}
}

void Projectile::activate(sf::Vector2f position)
{
	GameObject::activate(position);
	sound.play();
}
