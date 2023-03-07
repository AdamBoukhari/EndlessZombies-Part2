#pragma once

#include "GameObject.h"

class Background : public GameObject
{
public: 
	const std::string TEXTURE_BACKGROUND_NAME = "Field";
	const std::string TEXTURE_BACKGROUND_PATH = "Images\\Field.jpg";

	Background();
	void init(IAssetManager* assetManager);
};

