#pragma once
#include <Texture.h>
/*
 * Game Object class
 */
class Object {

private:

	float x;
	float y;
	float width;
	float height;
	float rotation;
	LTexture* sprite;
	SDL_Rect* collider;
	float* circleCollider;
	int colliderType;

	/*****************************************************************************/
public:

	//Constructors
	Object();
	Object(float, float);
	Object(float, float, float, float, float, LTexture*);
	Object(float, float, float, float, float, LTexture*, SDL_Rect*);
	Object(float, float, float, float, float, LTexture*, float*);

	//Deallocate memory
	~Object();


	void Update();

	//Getters & setters (encapsulation)
	void SetPosition(float, float);
	void SetSize(float, float);
	void SetRotation(float);
	void SetSprite(LTexture);
	void SetCollider(SDL_Rect);

	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();
	float GetRotation();
	LTexture* GetSprite();
	SDL_Rect* GetCollider();
	float* GetRadius();
	int GetTypeCollision();

};

/*****************************************************************************/

enum colliderTypes : int {	//Unscoped enum
	none = 0,
	rect = 1,
	circle = 2
};