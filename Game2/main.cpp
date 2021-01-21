#pragma region Includes

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <time.h>

#include "Texture.h"
#include "Scene.h"
#include "Object.h"
#include "SpaceShip.h"
#include "Spawner.h"

#include "GraphicsManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "SceneManager.h"
#include "TimeManager.h"

#pragma endregion

/**
 * Shoot 'em up game
 */

#pragma region Attributes

//Global texture paths
std::string spaceShipTexturePath = "./../../Media/spaceship.png";
std::string bulletTexturePath = "./../../Media/shot.png";
std::string enemyTexturePath = "./../../Media/enemy.png";
std::string backgroundTexturePath = "./../../Media/backgroundShootemUp.png";

//Global collider values
SDL_Rect spaceShipColliderInit = { 0, 0, 100, 100 };
SDL_Rect enemyColliderInit = { 0, 0, 63, 68 };
SDL_Rect bulletColliderInit = { 0, 0, 30, 30 };

#pragma endregion


#pragma region Custom Methods

bool Init()
{
	//Engine Managers
	TimeManager::CreateSingleton();
	InputManager::CreateSingleton();
	SceneManager::CreateSingleton();
	PhysicsManager::CreateSingleton();
	GraphicsManager::CreateSingleton();

	//Initialize Graphics Manager
	if (!GraphicsManager::GetInstance().Init())
	{
		printf("Failed to initialize Graphics Manager\n");
		return false;
	}
	return true;
}

bool LoadTextures()
{
	//SPACESHIP
	bool success = true;
	LTexture spaceShipTexture;
	if (!spaceShipTexture.loadFromFile(spaceShipTexturePath))
	{
		printf("Failed to load %s\n", spaceShipTexturePath.c_str());
		success = false;
	}

	//ENEMY
	LTexture enemyTexture;
	if (!enemyTexture.loadFromFile(enemyTexturePath))
	{
		printf("Failed to load %s\n", enemyTexturePath.c_str());
		success = false;
	}

	//BULLET
	LTexture BulletTexture;
	if (!BulletTexture.loadFromFile(bulletTexturePath))
	{
		printf("Failed to load %s\n", bulletTexturePath.c_str());
		success = false;
	}

	//BACKGROUND
	LTexture backgroundTexture;
	if (!backgroundTexture.loadFromFile(backgroundTexturePath))
	{
		printf("Failed to load %s\n", backgroundTexturePath.c_str());
		success = false;
	}

	return success;
}

void Destroy()
{
	//Engine Managers
	GraphicsManager::DestroySingleton();
	PhysicsManager::DestroySingleton();
	SceneManager::DestroySingleton();
	InputManager::DestroySingleton();
	TimeManager::DestroySingleton();
}
#pragma endregion

//									MAIN
/*****************************************************************************/
#pragma region Main method

int main(int argc, char* args[])
{
	if (Init()) {
		if (LoadTextures()) {	//Once Managers can load media

			srand((unsigned)time(NULL));

			//Create scene and set it as current
			Scene* scene = SceneManager::GetInstance().Create();
			SceneManager::GetInstance().SetCurrentScene(scene);

			/* OBJECT CONSTRUCTION AND CREATION */

			LTexture* spaceShipTexture = GraphicsManager::GetInstance().LoadTexture(spaceShipTexturePath);
			SDL_Rect* spaceShipCollider = PhysicsManager::GetInstance().LoadCollider(&spaceShipColliderInit);
			SpaceShip* player = new SpaceShip(GraphicsManager::SCREEN_WIDTH/2-50, GraphicsManager::SCREEN_HEIGHT - 100 , 100, 100, 0, spaceShipTexture, spaceShipCollider);		//Left paddle

			LTexture* bulletTexture = GraphicsManager::GetInstance().LoadTexture(bulletTexturePath);
			SDL_Rect* bulletCollider = PhysicsManager::GetInstance().LoadCollider(&bulletColliderInit);

			player->SetBulletAttributes(30,30,bulletTexture,bulletCollider);
			scene->AddObject(player);

			LTexture* enemyTexture = GraphicsManager::GetInstance().LoadTexture(enemyTexturePath);
			SDL_Rect* enemyCollider = PhysicsManager::GetInstance().LoadCollider(&enemyColliderInit);
			Spawner* enemySpawner = new Spawner(63, 68, 1.5, enemyTexture, enemyCollider);
			enemySpawner->SetBulletAttributes(30, 30, bulletTexture, bulletCollider);

			scene->AddObject(enemySpawner);

			/* -------------------------------- */

			bool quit = false;

			//Event handler
			SDL_Event eventHandler;

			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&eventHandler) != 0)
				{
					//User closes the window
					if (eventHandler.type == SDL_QUIT)
					{
						quit = true;
					}
					//Handle players' events
					scene->HandleEvents(eventHandler);
				}

				TimeManager::GetInstance().Update();

				//Calculate delta time in seconds
				float dt = TimeManager::GetInstance().GetDeltaTime();
				dt /= 1000;

				InputManager::GetInstance().Update();

				//Update scene
				scene->Update(dt);

				//Check collisions
				PhysicsManager::GetInstance().CheckCollisions();

				//Clear screen with texture
				SDL_Texture* texture = IMG_LoadTexture(GraphicsManager::GetInstance().GetRenderer(), backgroundTexturePath.c_str());
				SDL_Rect texture_rect;
				texture_rect.x = 0;
				texture_rect.y = 0;
				texture_rect.w = GraphicsManager::SCREEN_WIDTH;
				texture_rect.h = GraphicsManager::SCREEN_HEIGHT;

				SDL_RenderClear(GraphicsManager::GetInstance().GetRenderer());
				SDL_RenderCopy(GraphicsManager::GetInstance().GetRenderer(), texture, NULL, &texture_rect);

				//Render objects
				GraphicsManager::GetInstance().Render();

				//Update screen
				SDL_RenderPresent(GraphicsManager::GetInstance().GetRenderer());
			}

			//Delete scene
			SceneManager::GetInstance().Delete(scene);
		}
	}

	Destroy();

	return 0;
}
#pragma endregion

/*****************************************************************************/