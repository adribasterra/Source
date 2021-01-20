
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

/*
 * Shoot 'em up game
 */

 //Global texture names
std::string spaceShipTexturePath = "./../../Media/spaceship.png";
std::string bulletTexturePath = "./../../Media/shot.png";
std::string enemyTexturePath = "./../../Media/enemy.png";
std::string bckTexturePath = "./../../Media/backgroundShootemUp.png";
//Global colliders
SDL_Rect spaceShipColliderInit = { 0, 0, 100, 100 };
SDL_Rect enemyColliderInit = { 0, 0, 63, 68 };
SDL_Rect bulletColliderInit = { 0, 0, 30, 30 };
//Global audio sources
std::string soundPath = "./../../Media/Sound/Explosion2.wav";

bool Init() {
	//Init phase
	TimeManager::CreateSingleton();
	InputManager::CreateSingleton();
	SceneManager::CreateSingleton();
	PhysicsManager::CreateSingleton();
	GraphicsManager::CreateSingleton();

	//Initialize Managers
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
	LTexture SpaceShipTexture;
	if (!SpaceShipTexture.loadFromFile(spaceShipTexturePath)) success = false;

	LTexture EnemyTexture;
	if (!EnemyTexture.loadFromFile(enemyTexturePath)) success = false;

	LTexture BulletTexture;
	if (!BulletTexture.loadFromFile(bulletTexturePath)) success = false;

	LTexture BckTexture;
	if (!BckTexture.loadFromFile(bckTexturePath)) success = false;
	//Add it to the graphicsManager

	return success;
}

bool LoadColliders()
{
	//Add them to physicsManager

	return true;
}

void Destroy() {

	//Destroy phase
	GraphicsManager::DestroySingleton();
	PhysicsManager::DestroySingleton();
	SceneManager::DestroySingleton();
	InputManager::DestroySingleton();
	TimeManager::DestroySingleton();
}

//									MAIN
/*****************************************************************************/

int main(int argc, char* args[])
{
	if (Init()) {
		if (LoadTextures && LoadColliders) {	//Once Managers can load stuff

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

			player->setBulletAttributes(30,30,bulletTexture,bulletCollider);
			scene->AddObject(player);

			LTexture* enemyTexture = GraphicsManager::GetInstance().LoadTexture(enemyTexturePath);
			SDL_Rect* enemyCollider = PhysicsManager::GetInstance().LoadCollider(&enemyColliderInit);
			Spawner* enemySpawner = new Spawner(63, 68, 1.5, enemyTexture, enemyCollider);
			enemySpawner->setBulletAttributes(30, 30, bulletTexture, bulletCollider);

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
				InputManager::GetInstance().Update();

				//Calculate delta time in seconds
				float dt = TimeManager::GetInstance().GetDeltaTime();
				dt /= 1000;

				//Update scene
				scene->Update(dt);

				//Move objects
				//leftPaddle->Move();
				//rightPaddle->Move();

				//Check collisions
				PhysicsManager::GetInstance().CheckCollisions();

				//Clear screen
				SDL_Texture* texture = IMG_LoadTexture(GraphicsManager::GetInstance().GetRenderer(), bckTexturePath.c_str());
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
