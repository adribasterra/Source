#pragma once

#include "Object.h"
#include <vector>

/**
 * Scene class
 */
class Scene
{

private:

	std::vector<Object*> objects;

	/*****************************************************************************/
public:

	//Constructors
	Scene();
	~Scene();

	void Update(float dt);
	void HandleEvents(SDL_Event);

	//Delete all objects
	void Clear();
	
	//Handle objects
	void AddObject(Object*);
	void DeleteObject(Object*);

	//Getters
	Object* GetObject(int index);
	Object* GetObject(Object*);
	std::vector<Object*> GetObjectsInScene();

	/*****************************************************************************/
};