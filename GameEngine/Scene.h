#pragma once

#include "Object.h"

/*
 * Scene class
 */
class Scene {

private:

	int numObjects;
	Object objects[];		//Necesita ser un vector de la clase vector

	/*****************************************************************************/
public:

	//Constructor
	Scene();

	//Deallocate memory
	~Scene();

	void Update();

	void AddObject(Object objToAdd);

	void Clear();

	//Getters & setters
	Object GetObject(Object* searchingObj);

	void SetArraySize(int sizeObj);

};