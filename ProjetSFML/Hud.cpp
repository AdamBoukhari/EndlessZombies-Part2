#include "Hud.h"

Hud::Hud(View* view, DisplayObject* score, DisplayObject* timer, DisplayObject* livesCounter)
{
	this->score = score;
	this->timer = timer;
	this->livesCounter = livesCounter;
	this->view = view;
	this->screenWidth = 0;
	this->screenHeight = 0;
	this->worldWidth = 0;
	this->worldHeight = 0;
}

void Hud::init(IAssetManager* assetManager, int screenWidth, int screenHeight, int worldWidth, int worldHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->worldWidth = worldWidth;
	this->worldHeight = worldHeight;

	score->init(assetManager);
	timer->init(assetManager);
	livesCounter->init(assetManager);

	view->reset(sf::FloatRect(0.0f, 0.0f, (float)screenWidth, (float)screenHeight));
	view->setCenter(worldWidth / 2.0f, worldHeight / 2.0f);


	limits.minX = screenWidth / 2.0f;
	limits.maxX = worldWidth - limits.minX;
	limits.minY = screenHeight / 2.0f;
	limits.maxY = worldHeight - limits.minY;
}

void Hud::draw(RenderWindow& mainWin)
{
	mainWin.setView(*view);
	mainWin.draw(*score);
	mainWin.draw(*timer);
	mainWin.draw(*livesCounter);
}


void Hud::update(const sf::Vector2f& position)
{
	view->setCenter(position);

	if (view->getCenter().x < limits.minX)
	{
		view->setCenter(limits.minX, view->getCenter().y);
	}
	if (view->getCenter().x > limits.maxX)
	{
		view->setCenter(limits.maxX, view->getCenter().y);
	}
	if (view->getCenter().y < limits.minY)
	{
		view->setCenter(view->getCenter().x, limits.minY);
	}
	if (view->getCenter().y > limits.maxY)
	{
		view->setCenter(view->getCenter().x, limits.maxY);
	}


	sf::Vector2f scorePosition;
	scorePosition.x = view->getCenter().x - (screenWidth / 2);
	scorePosition.y = view->getCenter().y - (screenHeight / 2);
	score->setPosition(scorePosition);

	sf::Vector2f timerPosition;
	timerPosition.x = view->getCenter().x;
	timerPosition.y = view->getCenter().y - (screenHeight / 2);
	timer->setPosition(timerPosition);

	sf::Vector2f livesCounterPosition;
	livesCounterPosition.x = view->getCenter().x+ (screenWidth / 4);
	livesCounterPosition.y = view->getCenter().y - (screenHeight / 2);
	livesCounter->setPosition(livesCounterPosition);
}

DisplayObject* Hud::getScore() const
{
	return score;
}

DisplayObject* Hud::getTimer() const
{
	return timer;
}

DisplayObject* Hud::getLivesCounter() const
{
	return livesCounter;
}
