#include "GameMovingObject.h"

GameMovingObject::GameMovingObject()
{
	angleInRadians = 0.0f;
	speed = 0.0f;
	cosinus = 0.0f;
	sinus = 0.0f;
	hasDestination = false;
}

void GameMovingObject::init(IAssetManager* assetManager, std::string soundName, std::string soundFileNameAndPath)
{
	assetManager->loadSound(soundName, soundFileNameAndPath);
	sound.setBuffer(assetManager->getSound(soundName));
}

bool GameMovingObject::testCollisionBoxes(const sf::Sprite& sprite) const
{
	return (this->getGlobalBounds().intersects(sprite.getGlobalBounds()));
}

bool GameMovingObject::testCollisionCircles(const sf::Sprite& sprite) const
{
	float radius1 = this->getTexture()->getSize().x / 2.0f;
	float radius2 = sprite.getTexture()->getSize().x / 2.0f;

	float distance = sqrtf(pow(this->getPosition().x - sprite.getPosition().x, 2.0f) + pow(this->getPosition().y - sprite.getPosition().y, 2.0f));

	if (distance <= radius1 + radius2) return true;
	return false;
}

void GameMovingObject::setSpeed(float speed)
{
	this->speed = speed;
}
float GameMovingObject::getSpeed()
{
	return this->speed;
}

void GameMovingObject::setLimits(float maxX, float maxY)
{
	limits.maxX = maxX;
	limits.maxY = maxY;

	float halfTextureX = getTexture()->getSize().x / 2.0f;
	float halfTextureY = getTexture()->getSize().y / 2.0f;

	limits.minX += halfTextureX;
	limits.maxX -= halfTextureX;
	limits.minY += halfTextureY;
	limits.maxY -= halfTextureY;
}

float GameMovingObject::getSavedRotationRadianAngle() const
{
	return angleInRadians;
}

void GameMovingObject::saveRotationRadianAngle(const float angle)
{
	angleInRadians = angle;
}

void GameMovingObject::initDirectionOnXAndY(float angleInRadians)
{
	//Pour corriger overhead, deuxème version
	cosinus = cos(angleInRadians);
	sinus = sin(angleInRadians);  //ne pas appeler les attributs "sin" et "cos"
	hasDestination = false;
}

void GameMovingObject::setDestination(const sf::Vector2f& destination)
{
	hasDestination = true;
	this->destination = destination;

	//atan2f gère l'angle négatif contraitement à atan2
	//Donc pas besoin de gérer le changement de direction, il va se faire tout seul, grâce à l'angle
	//Calcul à effectuer :
	//			atan2f((PositionCibleY – PositionActuelleY), (PositionCibleX – PositionActuelleX));
	//			à vous de changer les paramètres pour obtenir les bonnes valeurs
	angleInRadians = atan2f((destination.y - getPosition().y), (destination.x - getPosition().x));
}

sf::Vector2f GameMovingObject::getOffset() const
{
	sf::Vector2f offset;

	if (!hasDestination)
	{
		if (cosinus == 0.0f && sinus == 0.0f) throw std::runtime_error("GameMovingObject::getOffset(): methode initDirectionOnXAndY() n'a pas ete prealablement appelee.");
		offset.x = cosinus * speed;
		offset.y = sinus * speed;
	}
	else if ((abs(destination.x - getPosition().x) <= speed) && (abs(destination.y - getPosition().y) <= speed))
	{
		//Arrivé à la destination
		offset.x = 0.0f;
		offset.y = 0.0f;
	}
	else 
	{
		//Pas arrivé à la destination.
		offset.x = cos(angleInRadians) * speed;
		offset.y = sin(angleInRadians) * speed;
	}

	return offset;
}

void GameMovingObject::reverseDirectionOnX()
{
	cosinus *= -1;
}

void GameMovingObject::reverseDirectionOnY()
{
	sinus *= -1;
}