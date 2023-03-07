#include "AssetManager.h"


void AssetManager::loadTexture(std::string name, std::string filename) {
	if (textures.count(name) == 0)
	{
		if (!textures[name].loadFromFile(filename)) throw std::runtime_error("AssetManager::loadTexture texture not found at: " + filename);
	}
}

sf::Texture& AssetManager::getTexture(std::string name) {
	return textures.at(name);
}

void AssetManager::loadFont(std::string name, std::string filename) {
	if (fonts.count(name) == 0) {
		if (!fonts[name].loadFromFile(filename))  throw std::runtime_error("AssetManager::loadFont texture not found at: " + filename);
	}

}

sf::Font& AssetManager::getFont(std::string name) {
	return fonts.at(name);
}

void AssetManager::loadSound(std::string name, std::string filename)
{
	if (buffers.count(name) == 0)
	{
		if (!buffers[name].loadFromFile(filename)) throw std::runtime_error("AssetManager::loadBuffer sound not found at: " + filename);
	}
}

sf::SoundBuffer& AssetManager::getSound(std::string name)
{
	return buffers.at(name);
}
