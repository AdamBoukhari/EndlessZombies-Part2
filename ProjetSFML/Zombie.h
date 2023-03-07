#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include "IObserver.h"
#include "Game.h"


class Zombie : public IObserver
{
public:
	static const int NB_ZOMBIE = 10;

	const float SPEED_INITIAL_VALUE = 4.0f;
	const float SUPER_SPEED_MULTIPLIER = 1.5f;

	const std::string ZOMBIE_NORMAL_TEXTURE_NAME = "Zombie1";
	const std::string FILE_PATH_ZOMBIE_NORMAL = "Images\\Zombie1.png";

	const std::string ZOMBIE_SUPER_SAYAN_TEXTURE_NAME = "Zombie2";
	const std::string FILE_PATH_ZOMBIE_SUPER_SAYAN = "Images\\Zombie2.png";

	const std::string SOUND_NAME_ZOMBIE_DEATH = "ZombieDeath";
	const std::string FILE_PATH_ZOMBIE_DEATH = "Sounds\\Actors\\ZombieDeath.ogg";

	Zombie();
	void init(IAssetManager* assetManager);
	void moveToWithinLimits(const sf::Vector2f& offset);
	void deactivate();
	void update();
	void notify(Subject* subject);
private:
	const float RADS_TO_ANGLE = 57.295779513f; //360/2PI

	const sf::Texture* normalTexture; 
	const sf::Texture* superTexture;
	bool isSuperSayan = false;
	float radius = 0;

};

