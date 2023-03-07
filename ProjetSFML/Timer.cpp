#include "Timer.h"

Timer::Timer()
{
}

void Timer::init(IAssetManager* assetManager)
{
	DisplayObject::init(assetManager, FONT_NAME, FILE_PATH);
	setString(PREFIX + std::to_string(time));
}

void Timer::update()
{
	time--;
	setString(PREFIX + std::to_string(time));
}
