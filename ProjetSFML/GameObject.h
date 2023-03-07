#pragma once
#include <SFML/Graphics.hpp>
#include "IAssetManager.h"

class GameObject : public sf::Sprite
{
public:
	//TP2, ajout du mot cl� virtual, vous pouvez donc red�finir cette m�thode dans votre classe concr�te.
	virtual void activate(sf::Vector2f position);

	//TP2, ajout du mot cl� virtual, vous pouvez donc red�finir cette m�thode dans votre classe concr�te.
	virtual void deactivate();
	
	bool isActive() const;
	virtual void init(IAssetManager* assetManager) = 0;

private:
	bool active;

protected:
	GameObject();
	void init(IAssetManager* assetManager, std::string textureName, std::string textureFileNameAndPath); 
};

