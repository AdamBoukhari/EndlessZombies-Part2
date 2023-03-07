#pragma once

#include "IPlayerControlsBridge.h" //Pour avoir la définition de la struct Position

class IPlayerControls
{
public:
	virtual bool fired() = 0;
	virtual sf::Vector2f getOffset(float speed) = 0;
	virtual float getRotationRadianAngle() = 0;
};


