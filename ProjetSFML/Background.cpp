#include "Background.h"

Background::Background()
{
}

void Background::init(IAssetManager* assetManager)
{
	GameObject::init(assetManager, TEXTURE_BACKGROUND_NAME, TEXTURE_BACKGROUND_PATH);
	setPosition(0, 0);
}