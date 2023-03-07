#include "KeyboardAndMouse.h"

KeyboardAndMouse::KeyboardAndMouse(Fighter* fighter, RenderWindow* mainWin)
{
	this->fighter = fighter;
	this->mainWin = mainWin;
}

bool KeyboardAndMouse::fired()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

sf::Vector2f KeyboardAndMouse::getOffset(float speed)
{
	//Avec le clavier les directions sont franches
	//La technique ci-dessous permet d'�viter les comportents ou si par exemple le Player appui � la fois en haut et en bas, que arbitrairement une des deux directions soit choisie.
	int axe = 0;

	//On enregistre binairement chacune des touches de direction appuy�e.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		axe |= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		axe |= 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		axe |= 4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		axe |= 8;

	sf::Vector2f offset;
	offset.x = 0.0f; // Si on initialise pas � 0, on va avoir un bogue de positonnement du joueur car C++ initialise pas les float � 0 par d�faut.
	offset.y = 0.0f;

	switch (axe)
	{
		//Si on a une direction franche, c'est facile
	case 1:
		offset.x = speed;
		offset.y = 0.0f;
		break;
	case 2:
		offset.x = -speed;
		offset.y = 0.0f;
		break;
	case 4:
		offset.x = 0.0f;
		offset.y = -speed;
		break;
	case 8:
		offset.x = 0.0f;
		offset.y = speed;
		break;

		//Les chiffres suivants repr�sentes deux bits qui repr�sentent chaucn une direction.
	case 5:
		offset.x = speed * DIAGONALE_ANGLE;
		offset.y = -speed * DIAGONALE_ANGLE;
		break;
	case 9:
		offset.x = speed * DIAGONALE_ANGLE;
		offset.y = speed * DIAGONALE_ANGLE;
		break;
	case 6:
		offset.x = -speed * DIAGONALE_ANGLE;
		offset.y = -speed * DIAGONALE_ANGLE;
		break;
	case 10:
		offset.x = -speed * DIAGONALE_ANGLE;
		offset.y = speed * DIAGONALE_ANGLE;
		break;

	default:
		break;
	}
	return offset;
}

float KeyboardAndMouse::getRotationRadianAngle()
{
	sf::Vector2f mousePosition = mainWin->mapPixelToCoords(sf::Mouse::getPosition(*mainWin));
	return atan2f((mousePosition.y - fighter->getPosition().y), (mousePosition.x - fighter->getPosition().x));
}


