#pragma once

#include "Object.h"
#include <vector>
/*
 * Scene class
 */
class Scene {

private:

	int numObjects;
	std::vector<Object> objects;
	/*****************************************************************************/
public:

	//Constructor
	Scene();

	//Deallocate memory
	~Scene();

	void Update();

	void AddObject(Object objToAdd);
	void DeleteObject(int id);
	void Clear();

	//Getters & setters
	Object* GetObject(int index);

	//void SetArraySize(int sizeObj);

};