#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class IAssetManager
{
public:
	virtual void loadTexture(std::string name, std::string fileNameAndPath) = 0;
	virtual sf::Texture& getTexture(std::string name) = 0;

	virtual void loadFont(std::string name, std::string fileNameAndPath) = 0;
	virtual sf::Font& getFont(std::string name) = 0;

	virtual void loadSound(std::string name, std::string fileNameAndPath) = 0;
	virtual sf::SoundBuffer& getSound(std::string name) = 0;
};