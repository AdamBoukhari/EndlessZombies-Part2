#include "LivesCounter.h"

LivesCounter::LivesCounter()
{
}

void LivesCounter::init(IAssetManager* assetManager)
{
	DisplayObject::init(assetManager, FONT_NAME, FILE_PATH);
	nbLives = NB_LIVES_ON_START;
	setString(PREFIX + std::to_string(nbLives));
	setCharacterSize(CHARACTER_SIZE);
}

void LivesCounter::update()
{
	nbLives--;
	setString(PREFIX + std::to_string(nbLives));
}
