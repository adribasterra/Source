
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
/*
 * Pong game
 */

//Global texture paths
std::string leftPaddleTexturePath = "./../../Media/leftPaddle-black.png";
std::string rightPaddleTexturePath = "./../../Media/rightPaddle-black.png";
std::string ballTexturePath = "./../../Media/dot.png";
std::string bckTexturePath = "./../../Media/backgroundPong.jpg";

//Global audio paths
std::string ballSound = "./../../Media/Sound/low.wav";
std::string leftPaddleSound = "./../../Media/Sound/high.wav";
std::string rightPaddleSound = "./../../Media/Sound/scratch.wav";
std::string backgroundMusic = "./../../Media/Sound/pongBckMusic.wav";
//Global colliders
float ballColliderInit = 10;
SDL_Rect paddleColliderInit = { 0, 0, 25, 125 };


bool Init(){
	//Init phase
	TimeManager::CreateSingleton();
	InputManager::CreateSingleton();
	SceneManager::CreateSingleton();
	PhysicsManager::CreateSingleton();
	GraphicsManager::CreateSingleton();
	AudioManager::CreateSingleton();
	GameManager::CreateSingleton();

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
	if (!paddleTexture.loadFromFile(leftPaddleTexturePath)) success = false;

	//BALL
	LTexture ballTexture;
	if (!ballTexture.loadFromFile(ballTexturePath)) success = false;

	//BACKGROUND
	LTexture bckTexture;
	if (!bckTexture.loadFromFile(bckTexturePath)) success = false;

	return success;
}

bool LoadAudios()
{
	//Add them to audioManager
	bool success = true;

	if (!AudioManager::GetInstance().AddAudio(ballSound, AudioTypes::sound)) success = false;

	if (!AudioManager::GetInstance().AddAudio(rightPaddleSound, AudioTypes::sound)) success = false;

	if (!AudioManager::GetInstance().AddAudio(leftPaddleSound, AudioTypes::sound)) success = false;
	
	if (!AudioManager::GetInstance().AddAudio(backgroundMusic, AudioTypes::music)) success = false;

	return success;
}

void Destroy() {

	//Destroy phase
	GameManager::DestroySingleton();
	AudioManager::DestroySingleton();
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
		if (LoadTextures() && LoadAudios()) {	//Once Managers can load stuff

			//Create scene and set it as current
			Scene* scene = SceneManager::GetInstance().Create();
			SceneManager::GetInstance().SetCurrentScene(scene);

			AudioManager::GetInstance().PlayAudio(backgroundMusic);

			/* OBJECT CONSTRUCTION AND CREATION */
			

			LTexture* leftPaddleTexture = GraphicsManager::GetInstance().LoadTexture(leftPaddleTexturePath);
			LTexture* rightPaddleTexture = GraphicsManager::GetInstance().LoadTexture(rightPaddleTexturePath);
			SDL_Rect* paddleCollider = PhysicsManager::GetInstance().LoadCollider(&paddleColliderInit);
			Paddle* leftPaddle = new Paddle(20, GraphicsManager::SCREEN_HEIGHT / 2 - 125 / 2, 25, 125, 0, leftPaddleTexture, paddleCollider);		//Left paddle
			Paddle* rightPaddle = new Paddle(GraphicsManager::SCREEN_WIDTH - 45, GraphicsManager::SCREEN_HEIGHT / 2 - 125 / 2, 25, 125, 0, rightPaddleTexture, paddleCollider);	//Right paddle
			scene->AddObject(leftPaddle);
			scene->AddObject(rightPaddle);

			//Set controls to paddles
			leftPaddle->SetControls(SDL_SCANCODE_W, SDL_SCANCODE_S);
			rightPaddle->SetControls(SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);

			GameManager::GetInstance().AddAudios(leftPaddleSound, rightPaddleSound);


			LTexture* ballTexture = GraphicsManager::GetInstance().LoadTexture(ballTexturePath);
			float* ballCollider = PhysicsManager::GetInstance().LoadCollider(&ballColliderInit);
			Ball* ball = new Ball(100, 10, 20, 20, 0, ballTexture, ballCollider, ballSound);					//Ball
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
					//leftPaddle->HandleEvent(eventHandler);
					//rightPaddle->HandleEvent(eventHandler);
				}

				TimeManager::GetInstance().Update();
				//Calculate delta time in seconds
				float dt = TimeManager::GetInstance().GetDeltaTime();
				dt /= 1000;

				InputManager::GetInstance().Update();

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
