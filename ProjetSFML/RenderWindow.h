#pragma once
#include <SFML/Graphics.hpp>

class RenderWindow
	:public sf::RenderWindow
{
public:
	virtual void create(sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
	virtual sf::Vector2f mapPixelToCoords(const sf::Vector2i& point) const;
	virtual void setVerticalSyncEnabled(bool enabled);
	virtual bool isOpen() const;
	virtual bool pollEvent(sf::Event& event);
	virtual void close();
	virtual void clear(const sf::Color& color = sf::Color(0, 0, 0, 255));
	virtual void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
	virtual void display();
};

