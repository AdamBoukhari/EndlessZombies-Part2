#pragma once
#include "RenderWindow.h"
#include "DisplayObject.h"
#include "View.h"
#include "IAssetManager.h"

//TP2: On regroupe les objets d'affichage dans cette classe
class IHud
{
public:

	virtual void init(IAssetManager* assetManager, int screenWidth, int screenHeight, int worldWidth, int worldHeight) = 0;
	virtual void draw(RenderWindow& mainWin) = 0;
	virtual void update(const sf::Vector2f& position) = 0;

	virtual DisplayObject* getScore() const = 0;
	virtual DisplayObject* getTimer() const = 0;
	virtual DisplayObject* getLivesCounter() const = 0;
};

