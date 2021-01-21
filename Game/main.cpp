#pragma region Includes

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Texture.h"
#include "Scene.h"
#include "Object.h"
#include "Paddle.h"
#include "Ball.h"
#include "GameManager.h"

#include "GraphicsManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "AudioManager.h"

#pragma endregion

/**
 * Pong game
 */
#pragma region Attributes

//Global texture paths
std::string leftPaddleTexturePath = "./../../Media/leftPaddle-black.png";
std::string rightPaddleTexturePath = "./../../Media/rightPaddle-black.png";
std::string ballTexturePath = "./../../Media/dot.png";
std::string backgroundTexturePath = "./../../Media/backgroundPong.jpg";

//Global collider values
float ballColliderInit = 10;
SDL_Rect paddleColliderInit = { 0, 0, 25, 125 };

//Global audio source paths
std::string ballSoundPath = "./../../Media/Sound/low.wav";
std::string leftPaddleSoundPath = "./../../Media/Sound/high.wav";
std::string rightPaddleSoundPath = "./../../Media/Sound/scratch.wav";
std::string backgroundMusicPath = "./../../Media/Sound/pongBckMusic.wav";
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
	//Extension Managers
	AudioManager::CreateSingleton();
	//Game Managers
	GameManager::CreateSingleton();

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
	bool success = true;

	//PADDLES
	LTexture paddleTexture;
	if (!paddleTexture.loadFromFile(leftPaddleTexturePath))
	{
		printf("Failed to load %s\n", leftPaddleTexturePath.c_str());
		success = false;
	}
	if (!paddleTexture.loadFromFile(rightPaddleTexturePath))
	{
		printf("Failed to load %s\n", rightPaddleTexturePath.c_str());
		success = false;
	}

	//BALL
	LTexture ballTexture;
	if (!ballTexture.loadFromFile(ballTexturePath))
	{
		printf("Failed to load %s\n", ballTexturePath.c_str());
		success = false;
	}

	//BACKGROUND
	LTexture bckTexture;
	if (!bckTexture.loadFromFile(backgroundTexturePath))
	{
		printf("Failed to load %s\n", backgroundTexturePath.c_str());
		success = false;
	}

	return success;
}

bool LoadAudios()
{
	bool success = true;

	//PADDLES
	if (!AudioManager::GetInstance().AddAudio(leftPaddleSoundPath, AudioTypes::sound))
	{
		printf("Failed to load %s\n", leftPaddleSoundPath.c_str());
		success = false;
	}
	if (!AudioManager::GetInstance().AddAudio(rightPaddleSoundPath, AudioTypes::sound))
	{
		printf("Failed to load %s\n", rightPaddleSoundPath.c_str());
		success = false;
	}

	//BALL
	if (!AudioManager::GetInstance().AddAudio(ballSoundPath, AudioTypes::sound))
	{
		printf("Failed to load %s\n", ballSoundPath.c_str());
		success = false;
	}

	//BACKGROUND
	if (!AudioManager::GetInstance().AddAudio(backgroundMusicPath, AudioTypes::music))
	{
		printf("Failed to load %s\n", backgroundMusicPath.c_str());
		success = false;
	}

	return success;
}

void Destroy()
{
	//Game Managers
	GameManager::DestroySingleton();
	//Extension Managers
	AudioManager::DestroySingleton();
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

int main( int argc, char* args[] )
{
	if (Init()) {
		if (LoadTextures() && LoadAudios()) {	//Once Managers can load media

			//Create scene and set it as current
			Scene* scene = SceneManager::GetInstance().Create();
			SceneManager::GetInstance().SetCurrentScene(scene);

			//Start playing music
			AudioManager::GetInstance().PlayAudio(backgroundMusicPath);

			/* OBJECT CONSTRUCTION AND CREATION */

			//PADDLES
			LTexture* leftPaddleTexture = GraphicsManager::GetInstance().LoadTexture(leftPaddleTexturePath);
			LTexture* rightPaddleTexture = GraphicsManager::GetInstance().LoadTexture(rightPaddleTexturePath);
			SDL_Rect* paddleCollider = PhysicsManager::GetInstance().LoadCollider(&paddleColliderInit);
			const int centeredY = GraphicsManager::SCREEN_HEIGHT / 2 - 125 / 2;
			Paddle* leftPaddle = new Paddle(20, centeredY, 25, 125, 0, leftPaddleTexture, paddleCollider);
			Paddle* rightPaddle = new Paddle(GraphicsManager::SCREEN_WIDTH - 45, centeredY, 25, 125, 0, rightPaddleTexture, paddleCollider);
			scene->AddObject(leftPaddle);
			scene->AddObject(rightPaddle);

			//Set controls to paddles
			leftPaddle->SetControls(SDL_SCANCODE_W, SDL_SCANCODE_S);
			rightPaddle->SetControls(SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);

			//Set paddles audio
			GameManager::GetInstance().AddAudios(leftPaddleSoundPath, rightPaddleSoundPath);

			//BALL
			LTexture* ballTexture = GraphicsManager::GetInstance().LoadTexture(ballTexturePath);
			float* ballCollider = PhysicsManager::GetInstance().LoadCollider(&ballColliderInit);
			Ball* ball = new Ball(100, 10, 20, 20, 0, ballTexture, ballCollider, ballSoundPath);
			scene->AddObject(ball);

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

				//Clear screen
				SDL_Texture* texture = IMG_LoadTexture(GraphicsManager::GetInstance().GetRenderer(), backgroundTexturePath.c_str());
				SDL_Rect texture_rect;
				texture_rect.x = 0;
				texture_rect.y = 0;
				texture_rect.w = GraphicsManager::SCREEN_WIDTH;
				texture_rect.h = GraphicsManager::SCREEN_HEIGHT;

				SDL_RenderClear(GraphicsManager::GetInstance().GetRenderer());
				SDL_RenderCopy(GraphicsManager::GetInstance().GetRenderer(), texture, NULL, &texture_rect);
				/*SDL_SetRenderDrawColor(GraphicsManager::GetInstance().GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(GraphicsManager::GetInstance().GetRenderer());*/
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