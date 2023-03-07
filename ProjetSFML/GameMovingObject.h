#pragma once

#include <SFML/Graphics.hpp>
#include "Subject.h"
#include "Limits.h"

using std::vector;

class GameMovingObject : public Subject
{
public:
	bool testCollisionBoxes(const sf::Sprite& sprite) const;
	bool testCollisionCircles(const sf::Sprite& sprite) const;

	void setSpeed(float speed);
	float getSpeed();

	void setLimits(float maxX, float maxY);
	float getSavedRotationRadianAngle() const;
	void saveRotationRadianAngle(const float angle);

	void setDestination(const sf::Vector2f& destination); //TP2
	void initDirectionOnXAndY(float angleInRadians);
	sf::Vector2f getOffset() const;
	void reverseDirectionOnX();
	void reverseDirectionOnY();

	//TP2 Il faut remettre d�claration de init m�me si dans GameObject. 
	virtual void init(IAssetManager* assetManager) = 0; 
	virtual void moveToWithinLimits(const sf::Vector2f& offset) = 0;

	//TP2 M�thode � impl�menter pour g�rer l'�tat interne de l'objet.
	//Devrait �tre utile pour :
	//	-Fighter: r�activation apr�s le nombre de secondes prescrit.
	//	-Projectile: d�sactivation apr�s le nombre de secondes prescrit.
	//	-Zombie: faire r�aparaitre all�atoirement.
	virtual void update() = 0; 

protected:
	GameMovingObject();
	Limits limits;
	sf::Sound sound; //Ajout � l'architecture, TP2

	//Ajout � l'architecture, TP2
	void init(IAssetManager* assetManager, std::string soundName, std::string soundFileNameAndPath);

private:	
	float speed;
	float angleInRadians;
	float cosinus;
	float sinus;
	sf::Vector2f destination; //TP2
	bool hasDestination; //TP2
};


