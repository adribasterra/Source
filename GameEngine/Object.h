#pragma once

#include <Texture.h>

/**
 * Game Object class
 */
class Object {

protected:

	float centeredX;
	float centeredY;
	float width;
	float height;
	float rotation;
	LTexture* texture;
	SDL_Rect* collider;
	float* circleCollider;
	int colliderType;
	std::string tag;

	/*****************************************************************************/
public:

	//Constructors
	Object();
	Object(float, float);
	Object(float, float, float, float, float, LTexture*);
	Object(float, float, float, float, float, LTexture*, SDL_Rect*, std::string);
	Object(float, float, float, float, float, LTexture*, float*, std::string);

	//Deallocate memory
	~Object() {};

	//Overridden in game objects
	virtual void Update(float dt) {};
	virtual void HandleEvent(SDL_Event&) {};
	virtual void OnCollisionEnter(Object* other) {};

	//Setters
	void SetPosition(float, float);
	void SetSize(float, float);
	void SetRotation(float);
	void SetSprite(LTexture);
	void SetCollider(SDL_Rect);
	void SetTag(std::string);

	//Getters
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();
	float GetRotation();
	LTexture* GetTexture();
	SDL_Rect* GetCollider();
	float* GetRadius();
	int GetTypeCollision();
	std::string GetTag();

	/*****************************************************************************/
};

enum colliderTypes : int {	//Unscoped enum
	none = 0,
	rect = 1,
	circle = 2
};