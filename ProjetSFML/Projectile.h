#pragma once
#include "GameMovingObject.h"
#include "Game.h"

class Projectile : public GameMovingObject
{
public:
	static const int NB_PROJECTILES = 10;

	Projectile();
	void init(IAssetManager* assetManager);
	void moveToWithinLimits(const sf::Vector2f& offset);
	void update();
	void activate(sf::Vector2f position);

	const std::string TEXTURE_NAME = "Projectiles";
	const std::string FILE_PATH = "Images\\Bullet.png";


	const std::string GUNSHOT_NAME = "Gunshot";
	const std::string GUNSHOT_FILENAME = "Sounds\\Guns\\Bullet.ogg";

private:
	static const int NB_SECONDS = 1;
	const float SPEED = 30.0f;
	float radius = 0;
	int lifetime = 0;

	sf::Sound gunshotSound;
};


