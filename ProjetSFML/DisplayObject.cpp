#include "DisplayObject.h"

DisplayObject::DisplayObject()
{
}

void DisplayObject::init(IAssetManager* assetManager, std::string fontName, std::string fontFileNameAndPath)
{
	assetManager->loadFont(fontName, fontFileNameAndPath);
	setFont(assetManager->getFont(fontName));
}
