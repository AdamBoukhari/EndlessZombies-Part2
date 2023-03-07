#include "View.h"

void View::reset(const sf::FloatRect& rectangle)
{
	sf::View::reset(rectangle);
}
void View::setCenter(float x, float y)
{
	sf::View::setCenter(x, y);
}
void View::setCenter(const sf::Vector2f& center)
{
	sf::View::setCenter(center);
}
const sf::Vector2f& View::getCenter() const
{
	return sf::View::getCenter();
}