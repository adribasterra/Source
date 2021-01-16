#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Texture.h"
#include "Scene.h"
//Extension headers
#include "Music.h"
//Include objects from game2
// ...

#include "GraphicsManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "SceneManager.h"
#include "TimeManager.h"

/*
 * Shoot 'em up game
 */

//Global texture names


//Global colliders


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
	//PADDLES
	bool success = true;
	LTexture paddleTexture;
	if (!/*paddleTexture.loadFromFile(leftPaddleTexturePath)*/false) success = false;
	//Add it to the graphicsManager

	//BALL
	LTexture ballTexture;
	if (!/*ballTexture.loadFromFile(ballTexturePath)*/false) success = false;
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

			//Create scene and set it as current
			Scene* scene = SceneManager::GetInstance().Create();
			SceneManager::GetInstance().SetCurrentScene(scene);

			/* OBJECT CONSTRUCTION AND CREATION */

			//Create textures, colliders and objects
			//Add objects to scene
			// ...

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
					//Add event handler from player
					// ...
				}

				TimeManager::GetInstance().Update();
				InputManager::GetInstance().Update();

				scene->Update(TimeManager::GetInstance().GetDeltaTime() / 1000);

				//Move objects
				// ...

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
