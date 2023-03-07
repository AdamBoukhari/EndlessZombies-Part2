#pragma once
#include "GameObject.h"
class Life : public GameObject
{
public:
	const std::string TEXTURE_LIFE_NAME = "Life";
	const std::string TEXTURE_LIFE_PATH = "Images\\Life.png";
	static const int NB_LIVES = 4;

	Life();
	void init(IAssetManager* assetManager);
};

