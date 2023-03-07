#include "RenderWindow.h"

void RenderWindow::create(sf::VideoMode mode, const sf::String& title, sf::Uint32 style, const sf::ContextSettings& settings)
{
	sf::RenderWindow::create(mode, title, style, settings);
}

sf::Vector2f RenderWindow::mapPixelToCoords(const sf::Vector2i& point) const
{
	return sf::RenderWindow::mapPixelToCoords(point);
}
void RenderWindow::setVerticalSyncEnabled(bool enabled)
{
	sf::RenderWindow::setVerticalSyncEnabled(enabled);
}
bool RenderWindow::isOpen() const
{
	return sf::RenderWindow::isOpen();
}
bool RenderWindow::pollEvent(sf::Event& event)
{
	return sf::RenderWindow::pollEvent(event);
}
void RenderWindow::close()
{
	sf::RenderWindow::close();
}
void RenderWindow::clear(const sf::Color& color)
{
	sf::RenderWindow::clear(color);
}
void RenderWindow::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
{
	sf::RenderWindow::draw(drawable, states);
}
void RenderWindow::display()
{
	sf::RenderWindow::display();
}