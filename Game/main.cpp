/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

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

#pragma region Dot declarations

//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move();

		//Shows the dot on the screen
		void render();

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Scene textures
LTexture gDotTexture;

#pragma endregion


#pragma region Dot functions

Dot::Dot()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; break;
            case SDLK_DOWN: mVelY += DOT_VEL; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY -= DOT_VEL; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void Dot::move()
{
	mVelX = 0;
	mVelY = 0;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) {
		mVelY -= DOT_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_DOWN)) {
		mVelY += DOT_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_LEFT)) {
		mVelX -= DOT_VEL;
	}
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_RIGHT)) {
		mVelX += DOT_VEL;
	}

	//Move the dot left or right
	mPosX += mVelX;

	//If the dot went too far to the left or right
	if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > GraphicsManager::SCREEN_WIDTH ) )
	{
		//Move back
		mPosX -= mVelX;
	}

	//Move the dot up or down
	mPosY += mVelY;

	//If the dot went too far up or down
	if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > GraphicsManager::SCREEN_HEIGHT ) )
	{
		//Move back
		mPosY -= mVelY;
	}
}

void Dot::render()
{
    //Show the dot
	gDotTexture.render( mPosX, mPosY );
}

/**
* Esto est� ahora en el GraphicsManager
*/
bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !gDotTexture.loadFromFile( "../../Media/dot.bmp" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gDotTexture.free();
}

#pragma endregion

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

			/* CONSTRUCCI�N DE OBJETOS */

			LTexture* paddleTexture = GraphicsManager::GetInstance().LoadTexture(paddleTexturePath);
			SDL_Rect* paddleCollider = PhysicsManager::GetInstance().LoadCollider(paddleColliderInit);
			Paddle* leftPaddle = new Paddle(0, 0, 20, 20, 0, paddleTexture, paddleCollider);		//Left paddle
			Paddle* rightPaddle = new Paddle(30, 30, 20, 20, 0, paddleTexture, paddleCollider);		//Right paddle
			scene->AddObject(leftPaddle);
			scene->AddObject(rightPaddle);

			LTexture* ballTexture = GraphicsManager::GetInstance().LoadTexture(ballTexturePath);
			float* ballCollider = PhysicsManager::GetInstance().LoadCollider(ballColliderInit);
			Ball* ball = new Ball(10, 10, 20, 20, 0, ballTexture, ballCollider);						//Ball
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
				}
				TimeManager::GetInstance().Update();

				InputManager::GetInstance().Update();
				if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) {

				}

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

	//Free resources and close SDL
	close();

	Destroy();

	return 0;
}

//#pragma region Dot game
//
////Start up SDL and create window
//if (!GraphicsManager::GetInstance().Init())
//{
//	printf("Failed to initialize!\n");
//}
//else
//{
//	//Load media
//	if (!loadMedia())
//	{
//		printf("Failed to load media!\n");
//	}
//	else
//	{
//		//Main loop flag
//		bool quit = false;
//
//		//Event handler
//		SDL_Event e;
//
//		//The dot that will be moving around on the screen
//		Dot dot;
//
//		//While application is running
//		while (!quit)
//		{
//
//			//Handle events on queue
//			while (SDL_PollEvent(&e) != 0)
//			{
//				//User requests quit
//				if (e.type == SDL_QUIT)
//				{
//					quit = true;
//				}
//
//				//Handle input for the dot
//				dot.handleEvent(e);
//			}
//
//			InputManager::GetInstance().Update();
//			if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) {
//
//			}
//			//Move the dot
//			dot.move();
//
//			//Clear screen
//			SDL_SetRenderDrawColor(GraphicsManager::GetInstance().GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
//			SDL_RenderClear(GraphicsManager::GetInstance().GetRenderer());
//
//			//Render objects
//			dot.render();
//
//			//Update screen
//			SDL_RenderPresent(GraphicsManager::GetInstance().GetRenderer());
//		}
//	}
//}
//
//#pragma endregion
//
