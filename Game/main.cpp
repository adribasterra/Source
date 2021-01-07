
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Texture.h"
#include "Scene.h"
#include "Object.h"
#include "Paddle.h"
#include "Ball.h"

#include "GraphicsManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "SceneManager.h"
#include "TimeManager.h"

//Global texture names
std::string paddleTexturePath = "./../../Media/dot.bmp";
std::string ballTexturePath = "./../../Media/dot.bmp";

//Global colliders
float ballColliderInit = 10;
SDL_Rect paddleColliderInit = { 0, 0, 20, 60 };

bool Init(){
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
	if (!paddleTexture.loadFromFile(paddleTexturePath)) success = false;
	//Add it to the graphicsManager

	//BALL
	LTexture ballTexture;
	if (!ballTexture.loadFromFile(ballTexturePath)) success = false;
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

int main( int argc, char* args[] )
{
	if (Init()) {
		if (LoadTextures && LoadColliders) {	//Once Managers can load stuff

			//Create scene and set it as current
			Scene* scene = SceneManager::GetInstance().Create();
			SceneManager::GetInstance().SetCurrentScene(scene);

			//Debug
			if (scene == SceneManager::GetInstance().GetCurrentScene()) printf("YAYY");

			/* CONSTRUCCIÓN DE OBJETOS */

			LTexture* paddleTexture = GraphicsManager::GetInstance().LoadTexture(paddleTexturePath);
			SDL_Rect* paddleCollider = PhysicsManager::GetInstance().LoadCollider(&paddleColliderInit);
			Paddle* leftPaddle = new Paddle(0, 0, 20, 20, 0, paddleTexture, paddleCollider);		//Left paddle
			Paddle* rightPaddle = new Paddle(30, 30, 20, 20, 0, paddleTexture, paddleCollider);		//Right paddle
			scene->AddObject(leftPaddle);
			scene->AddObject(rightPaddle);

			//Set controls to paddles
			leftPaddle->SetControls(SDL_SCANCODE_W, SDL_SCANCODE_S);
			rightPaddle->SetControls(SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);

			LTexture* ballTexture = GraphicsManager::GetInstance().LoadTexture(ballTexturePath);
			float* ballCollider = PhysicsManager::GetInstance().LoadCollider(&ballColliderInit);
			Ball* ball = new Ball(10, 10, 20, 20, 0, ballTexture, ballCollider);					//Ball
			scene->AddObject(ball);

			/* ----------------------- */

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
					leftPaddle->HandleEvent(eventHandler);
					rightPaddle->HandleEvent(eventHandler);
				}

				TimeManager::GetInstance().Update();
				InputManager::GetInstance().Update();

				if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) {

				}

				leftPaddle->Move();
				//rightPaddle->Move();

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
