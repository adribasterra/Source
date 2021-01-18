
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
 * Shoot'em up game
 */

 //Global texture names
std::string spaceShipTexturePath = "./../../Media/dot.bmp";

//Global colliders
SDL_Rect spaceShipColliderInit = { 0, 0, 50, 50 };

//Global audio sources
std::string soundPath = "./../../Media/Sound/explosion.mp3";

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
			SpaceShip* player = new SpaceShip(20, 25, 25, 25, 0, spaceShipTexture, spaceShipCollider);		//Left paddle

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

				//Update scene
				scene->Update(TimeManager::GetInstance().GetDeltaTime() / 1000);

				//Move objects
				//leftPaddle->Move();
				//rightPaddle->Move();

				//Check collisions
				PhysicsManager::GetInstance().CheckCollisions();

				//Clear screen
				SDL_SetRenderDrawColor(GraphicsManager::GetInstance().GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(GraphicsManager::GetInstance().GetRenderer());

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
