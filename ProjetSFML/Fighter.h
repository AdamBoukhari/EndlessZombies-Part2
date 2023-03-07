#pragma once
#include "GameMovingObject.h"

class Fighter : public GameMovingObject
{
public:
	const float SPEED_INITIAL_VALUE = 5.0f;


	const std::string TEXTURE_NAME_ALIVE = "Fighter";
	const std::string FILE_PATH_ALIVE = "Images\\Fighter.png";

	const std::string TEXTURE_NAME_FIGHGTER_DEAD = "Blood";
	const std::string FILE_PATH_FIGHTER_DEAD = "Images\\Blood.png";

	const std::string SOUND_NAME_FIGHTER_DEATH = "FighterDeath";
	const std::string FILE_PATH_FIGHTER_DEATH = "Sounds\\Actors\\FighterDeath.ogg";

	Fighter();
	void init(IAssetManager* assetManager);
	void moveToWithinLimits(const sf::Vector2f& offset);

	void activate(sf::Vector2f position);

	void deactivate();

	void update();

private:
	const float NB_SECONDS_DEAD = 2.0f;
	const sf::Texture* normalTexture;
	const sf::Texture* deadTexture;
	int nbFrameDead = 0;
};

