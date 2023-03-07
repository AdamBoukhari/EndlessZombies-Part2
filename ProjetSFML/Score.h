#pragma once
#include "DisplayObject.h"

class Score : public DisplayObject
{
public:
	Score();
	void init(IAssetManager* assetManager);
	void update();
	const std::string FONT_NAME = "GeneralDisplay";
	const std::string FILE_PATH = "Fonts\\segoepr.ttf";
private:
	int points = 0;
	const std::string PREFIX = "Score: ";

};

