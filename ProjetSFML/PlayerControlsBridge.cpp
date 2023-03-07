#include "PlayerControlsBridge.h"

PlayerControlsBridge::PlayerControlsBridge(IPlayerControls* joystick, IPlayerControls* keyboard)
{
    this->playersControls[0] = keyboard;
    this->playersControls[1] = joystick;
}


sf::Vector2f PlayerControlsBridge::getOffset(float speed)
{
    IPlayerControls* control = playerControlsFactory();
    return control->getOffset(speed);
}

float PlayerControlsBridge::getRotationRadianAngle()
{
    IPlayerControls* control = playerControlsFactory();
    return control->getRotationRadianAngle();
}

bool PlayerControlsBridge::playerFired()
{
    IPlayerControls* control = playerControlsFactory();
    return control->fired();
}

IPlayerControls* PlayerControlsBridge::playerControlsFactory()
{
    return this->playersControls[sf::Joystick::isConnected(0)];
}