#include "Joystick.h"

bool Joystick::fired()
{
	return sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < TRIGGER_TOLERANCE;
}

sf::Vector2f Joystick::getOffset(float speed)
{
	speed /= 100.0f;

	/*left axes*/
	sf::Vector2f offset;
	float axeX = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
	float axeY = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);

	if (abs(axeX) > NOISE)
	{
		offset.x = axeX * speed;
	}
	else
	{
		offset.x = 0;
	}

	if (abs(axeY) > NOISE)
	{
		offset.y = axeY * speed;
	}
	else
	{
		offset.y = 0;
	}
	return offset;
}

float Joystick::getRotationRadianAngle()
{
	sf::Vector2f rotationPosition;

	/*right axes*/
	float axeX = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
	float axeY = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);
	if (abs(axeX) > NOISE)
	{
		rotationPosition.x = axeX;
	}
	else
	{
		rotationPosition.x = 0;
	}

	if (abs(axeY) > NOISE)
	{
		rotationPosition.y = axeY;
	}
	else
	{
		rotationPosition.y = 0;
	}

	//Evaluation
	if (rotationPosition.x == 0.0f && rotationPosition.y == 0.0f) return 0.0f;

	if (rotationPosition.x == 0.0f) rotationPosition.x = 0.000001f;

	float rotationRad = atanf(rotationPosition.y / rotationPosition.x); 

	if (rotationPosition.x < 0)
	{
		rotationRad += PI;
	}

	return rotationRad;
}
