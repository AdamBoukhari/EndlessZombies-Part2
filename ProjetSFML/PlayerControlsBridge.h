#pragma once
#include "IPlayerControlsBridge.h"
#include "IPlayerControls.h"

class PlayerControlsBridge : public IPlayerControlsBridge
{
public:
	PlayerControlsBridge(IPlayerControls* joystick, IPlayerControls* keyboard);

	sf::Vector2f getOffset(float speed);
	float getRotationRadianAngle();
	bool playerFired();
private:
	IPlayerControls* playersControls[2];
	IPlayerControls* playerControlsFactory();
};

