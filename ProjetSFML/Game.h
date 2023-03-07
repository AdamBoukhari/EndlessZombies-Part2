#pragma once

#include "IPlayerControls.h"
#include "IPlayerControlsBridge.h"
#include "IAssetManager.h"
#include "RenderWindow.h"
#include "View.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp> 
#include "DisplayObject.h"
#include "GameObject.h"
#include "GameMovingObject.h"
#include "IHud.h"
#include "Projectile.h"
#include "Zombie.h"
#include "Timer.h"
#include "LivesCounter.h"
#include "Life.h"

class Game
{
public:
	Game(IPlayerControlsBridge* playerControlsBridge, RenderWindow* renderWindow, IAssetManager* assetManager, IHud* hud, GameObject* background, GameMovingObject* fighter, GameMovingObject** zombies, GameMovingObject** projectiles, GameObject** lives);
	void run();

	static const int SCREEN_WIDTH = 1302;
	static const int SCREEN_HEIGHT = 666; 

	static const int WORLD_WIDTH = 3384;
	static const int WORLD_HEIGHT = 1656;
	const sf::Vector2f CENTER = sf::Vector2f(WORLD_WIDTH / 2, WORLD_HEIGHT / 2);

	static const int NB_FPS = 60;
	static const int GAME_MAX_TIME = 60;

	const std::string NAME_MUSIC = "Music";
	const std::string FILE_PATH_MUSIC = "Sounds\\BGM\\Music.ogg";

private:
	const float RADS_TO_ANGLE = 57.295779513f; //360/2PI
	const float DIAGONALE_ANGLE = 0.707106781f;

	RenderWindow* mainWin;
	IAssetManager* assetManager;
	sf::Event event;
	IPlayerControlsBridge* playerControlsBridge;
	
	GameObject* background;
	IHud* hud; //TP2
	GameMovingObject* fighter;
	GameMovingObject** zombies;/*[Zombie::NB]*/
	GameMovingObject** projectiles;/*[Projectile::NB]*/
	GameObject** lives;/*[Life::NB]*/
	int numberOfFrames;
	int nbSeconds;
	int nbLives;
	sf::Sound sound;

	//Pour faire un decalage entre les tirs
	bool hasAlreadyShot = false;

	void init();
	void manageEvents();
	sf::Vector2f manageGameInputs();
	sf::Vector2f getRandomPosition(GameObject* object);
	void manageFighterMovements(const sf::Vector2f &offset);
	void manageZombiesMovements();
	void manageProjectilesMovements();
	void manageView();
	void draw();
	bool gameOver;
};