#pragma once
#include <SFML/Graphics.hpp> 
#include "IPlayerControls.h"
class Joystick
	: public IPlayerControls
{
public:
	static const int TRIGGER_TOLERANCE = -20;
	const float NOISE = 12;
	const float PI = 3.141592653f;

	bool fired();
	sf::Vector2f getOffset(float speed);
	float getRotationRadianAngle();
};

