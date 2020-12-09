#pragma once

#include "Object.h"

/*
 * Scene class
 */
class Scene {

private:

	int numObjects;
	Object objects[];

public:

	//Constructor
	Scene();

	//Deallocate memory
	~Scene();

	void Update();

	void AddObject(Object objToAdd);

	void clearScene();

	//Getters & setters
	Object GetObject(Object* searchingObj);

	void SetArraySize(int sizeObj);

};