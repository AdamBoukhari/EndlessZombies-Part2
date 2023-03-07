#pragma once
#include "DisplayObject.h"

class LivesCounter : public DisplayObject
{
public:
	LivesCounter();
	void init(IAssetManager* assetManager);
	void update();
	const std::string FONT_NAME = "GeneralDisplay";
	const std::string FILE_PATH = "Fonts\\segoepr.ttf";
	static const int NB_LIVES_ON_START = 3;

private:
	static const int CHARACTER_SIZE = 15;

	int nbLives;
	const std::string PREFIX = "Lives: ";
};
