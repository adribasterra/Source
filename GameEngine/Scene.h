#pragma once

#include "Object.h"
#include <vector>
/*
 * Scene class
 */
class Scene {

private:

	std::vector<Object*> objects;
	/*****************************************************************************/
public:

	//Constructor
	Scene();

	//Deallocate memory
	~Scene();

	void Update(float dt);
	void HandleEvents(SDL_Event);
	
	//void CreateObject();
	//void CreateObject(float, float);
	//void CreateObject(float, float, float, float, float, LTexture*);
	//void CreateObject(float, float, float, float, float, LTexture*, SDL_Rect*);
	//void CreateObject(float, float, float, float, float, LTexture*, float*);

	void AddObject(Object*);
	void DeleteObject(Object*);
	void Clear();

	//Getters & setters
	// es necesaria?
	Object* GetObject(int index);
	Object* GetObject(Object*);
	std::vector<Object*> GetObjectsInScene();
	//void SetArraySize(int sizeObj);

};