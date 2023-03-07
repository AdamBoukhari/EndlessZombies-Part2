#pragma once
#include <SFML/Graphics.hpp> 

class View
	:public sf::View
{
public:
	virtual void reset(const sf::FloatRect& rectangle);
	virtual void setCenter(float x, float y);
	virtual void setCenter(const sf::Vector2f& center);
	virtual const sf::Vector2f& getCenter() const;

};

