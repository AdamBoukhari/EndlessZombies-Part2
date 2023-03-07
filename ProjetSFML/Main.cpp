#include <vld.h>
#include <iostream>
#include "Game.h"
#include "View.h"
#include "Hud.h"
#include "Background.h"
#include "Fighter.h"
#include "Joystick.h"
#include "KeyboardAndMouse.h"
#include "PlayerControlsBridge.h"
#include "AssetManager.h"
#include "Projectile.h"
#include "Zombie.h"
#include "Score.h"
#include "Timer.h"
#include "LivesCounter.h"
#include "Life.h"

int main()
{
	bool exceptionHappened = false;
	GameMovingObject** projectiles;
	GameMovingObject** zombies;
	GameObject** lives;
	try {
		//Ici, déclarez tous vos objets sur la pile (stack)
		Background background;
		RenderWindow renderWindow;
		View view; //La vue doit être gérée par le Hud
		Score score;
		Timer timer;
		LivesCounter livesCounter;
		Hud hud(&view, &score, &timer, &livesCounter);
		Fighter fighter;
		Joystick joystick;
		AssetManager assetManager;
		KeyboardAndMouse keyboard(&fighter, &renderWindow);
		PlayerControlsBridge bridge(&joystick, &keyboard);
		projectiles = new GameMovingObject* [Projectile::NB_PROJECTILES];
		for (int i = 0; i < Projectile::NB_PROJECTILES; i++)
		{
			projectiles[i] = new Projectile();
		}

		zombies = new GameMovingObject * [Zombie::NB_ZOMBIE];
		for (int i = 0; i < Zombie::NB_ZOMBIE; i++)
		{
			zombies[i] = new Zombie();
		}

		lives = new GameObject * [Life::NB_LIVES];
		for (int i = 0; i < Life::NB_LIVES; i++)
		{
			lives[i] = new Life();
		}

		Game game(&bridge, &renderWindow, &assetManager, &hud, &background, &fighter, zombies, projectiles, lives);
		game.run();
	}
	catch (std::runtime_error& e)
	{
 		exceptionHappened = true;
		std::cout << e.what();
	}
	
	//Supprimez ici les mémoires allouées
	for (int i = 0; i < Projectile::NB_PROJECTILES; i++)
	{
		delete projectiles[i];
	}
	delete[] projectiles;

	for (int i = 0; i < Zombie::NB_ZOMBIE; i++)
	{
		delete zombies[i];
	}
	delete[] zombies;

	for (int i = 0; i < Life::NB_LIVES; i++)
	{
		delete lives[i];
	}
	delete[] lives;

	if (exceptionHappened)
	{
		return EXIT_FAILURE;  // -1
	}
	return EXIT_SUCCESS; // 0
}