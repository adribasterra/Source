
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Texture.h"
#include "Scene.h"
#include "Object.h"
#include "SpaceShip.h"

#include "GraphicsManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "AudioManager.h"

/*
 * Shoot 'em up game
 */

 //Global texture names
std::string spaceShipTexturePath = "./../../Media/spaceship.png";
std::string bulletTexturePath = "./../../Media/shot.png";
std::string enemyTexturePath = "./../../Media/enemy.png";
std::string bckTexturePath = "./../../Media/backgroundShootemUp.png";
//Global colliders
SDL_Rect spaceShipColliderInit = { 0, 0, 50, 50 };

//Global audio sources
std::string soundPath = "./../../Media/Sound/Explosion2.wav";

bool Init() {
	//Init phase
	TimeManager::CreateSingleton();
	InputManager::CreateSingleton();
	SceneManager::CreateSingleton();
	PhysicsManager::CreateSingleton();
	GraphicsManager::CreateSingleton();
	AudioManager::CreateSingleton();

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
	AudioManager::DestroySingleton();
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

			//Create scene and set it as current
			Scene* scene = SceneManager::GetInstance().Create();
			SceneManager::GetInstance().SetCurrentScene(scene);

			AudioManager::GetInstance().AddAudio(soundPath, AudioTypes::sound);
			AudioManager::GetInstance().PlayAudio(soundPath);

			/* OBJECT CONSTRUCTION AND CREATION */

			LTexture* spaceShipTexture = GraphicsManager::GetInstance().LoadTexture(spaceShipTexturePath);
			SDL_Rect* spaceShipCollider = PhysicsManager::GetInstance().LoadCollider(&spaceShipColliderInit);
			SpaceShip* player = new SpaceShip(20, 25, 100, 100, 0, spaceShipTexture, spaceShipCollider);		//Left paddle

			LTexture* bulletTexture = GraphicsManager::GetInstance().LoadTexture(bulletTexturePath);

			player->setBulletAttributes(30,30,bulletTexture,spaceShipCollider);
			scene->AddObject(player);

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
					player->HandleEvent(eventHandler);
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
