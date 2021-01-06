#pragma once

#include "Object.h"
#include <vector>
/*
 * Scene class
 */
class Scene {

private:

	std::vector<Object> objects;
	/*****************************************************************************/
public:

	//Constructor
	Scene();

	//Deallocate memory
	~Scene();

	void Update();

	void CreateObject();
	void CreateObject(float, float);
	void CreateObject(float, float, float, float, float, LTexture*);
	void CreateObject(float, float, float, float, float, LTexture*, SDL_Rect*);
	void CreateObject(float, float, float, float, float, LTexture*, float*);

	void AddObject(Object*);
	void DeleteObject(Object*);
	void Clear();

	//Getters & setters
	// es necesaria?
	Object* GetObject(int index);
	std::vector<Object>* GetObjectsInScene();
	//void SetArraySize(int sizeObj);

};