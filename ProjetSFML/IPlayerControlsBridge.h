#pragma once

#include <SFML/Graphics.hpp> //Pour avoir la d�finition de la struct sf::Vector2f

class IPlayerControlsBridge
{
public:
	virtual bool playerFired() = 0;
	virtual sf::Vector2f getOffset(float speed) = 0;
	virtual float getRotationRadianAngle() = 0;
};
