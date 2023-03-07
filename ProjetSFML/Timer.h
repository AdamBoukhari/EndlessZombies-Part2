#pragma once
#include "DisplayObject.h"

class Timer : public DisplayObject
{
public:
	Timer();
	void init(IAssetManager* assetManager);
	void update();
	const std::string FONT_NAME = "GeneralDisplay";
	const std::string FILE_PATH = "Fonts\\segoepr.ttf";
	static const int GAME_TIME_IN_SECONDES = 60;

private:
	int time = GAME_TIME_IN_SECONDES;
	const std::string PREFIX = "Time: ";
};


