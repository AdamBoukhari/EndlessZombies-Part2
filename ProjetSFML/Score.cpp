#include "Score.h"

Score::Score()
{
}

void Score::init(IAssetManager* assetManager)
{
	DisplayObject::init(assetManager, FONT_NAME, FILE_PATH);
	setString(PREFIX + std::to_string(points));
}

void Score::update()
{
	points++;
	setString(PREFIX + std::to_string(points));
}
