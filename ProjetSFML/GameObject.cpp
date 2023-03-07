#include "GameObject.h"

GameObject::GameObject()
{
	active = false;
}

void GameObject::init(IAssetManager* assetManager, std::string textureName, std::string textureFileNameAndPath)
{
	assetManager->loadTexture(textureName, textureFileNameAndPath);
	setTexture(assetManager->getTexture(textureName));
}

void GameObject::activate(sf::Vector2f position)
{
	setPosition(position.x, position.y);
	active = true;
}

void GameObject::deactivate()
{
	active = false;
}

bool GameObject::isActive() const
{
	return active;
}
