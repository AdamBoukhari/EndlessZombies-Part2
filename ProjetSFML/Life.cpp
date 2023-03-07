#include "Life.h"

Life::Life()
{
}

void Life::init(IAssetManager* assetManager)
{
	GameObject::init(assetManager, TEXTURE_LIFE_NAME, TEXTURE_LIFE_PATH);
}
