#pragma once
#include <SFML/Graphics.hpp>
#include "IAssetManager.h"

class DisplayObject : public sf::Text
{
public:
	virtual void update() = 0;
	virtual void init(IAssetManager* assetManager) = 0;
	
protected:
	DisplayObject();
	void init(IAssetManager* assetManager, std::string fontName, std::string fontFileNameAndPath);
};

