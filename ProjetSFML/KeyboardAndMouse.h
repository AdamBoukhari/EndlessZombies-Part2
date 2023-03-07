#pragma once
#include "IPlayerControls.h"
#include "Fighter.h"
#include "RenderWindow.h"

class KeyboardAndMouse : public IPlayerControls
{
public:
	const float DIAGONALE_ANGLE = 0.707106781f;

	KeyboardAndMouse(Fighter* fighter, RenderWindow* mainWin);

	bool fired();
	sf::Vector2f getOffset(float speed);
	float getRotationRadianAngle();
private:
	Fighter* fighter;
	RenderWindow* mainWin;
};
