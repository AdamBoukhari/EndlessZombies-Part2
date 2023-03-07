#pragma once

#include "IHud.h"
#include "IAssetManager.h"
#include "Limits.h"

class Hud : public IHud
{
public:
	Hud(View* view, DisplayObject* score, DisplayObject* timer, DisplayObject* livesCounter);
	void init(IAssetManager* assetManager, int screenWidth, int screenHeight, int worldWidth, int worldHeight);
	void draw(RenderWindow& mainWin);

	void update(const sf::Vector2f& position);
	DisplayObject* IHud::getScore() const;
	DisplayObject* IHud::getTimer() const;
	DisplayObject* IHud::getLivesCounter() const;

private:
	//Composantes
	View* view;

	DisplayObject* score;
	DisplayObject* timer;
	DisplayObject* livesCounter;

	int screenWidth;
	int screenHeight;
	int worldWidth;
	int worldHeight;
	Limits limits;
};

