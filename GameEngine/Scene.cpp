#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"

//								Constructors
/*****************************************************************************/
#pragma region Constructors

Scene::Scene()
{
	//Initialize
	objects = std::vector<Object*>();
	objects.reserve(10);
}

Scene::~Scene()
{
	//Delete objects
	this->Clear();
	//Clear vector
	objects.clear();
}
#pragma endregion

//								Main functions
/*****************************************************************************/
#pragma region Main functions

void Scene::Update(float dt)
{
	//Update all Scene's objects
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt);
	}
}

void Scene::HandleEvents(SDL_Event eventHandler)
{
	//Handle events of all Scene's objects
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->HandleEvent(eventHandler);
	}
}
#pragma endregion

//								Getters
/*****************************************************************************/
#pragma region Getters

Object* Scene::GetObject(int index)
{
	if (index < objects.size())
	{
		return objects[index];
	}
	return NULL;
}
Object* Scene::GetObject(Object* obj)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] == obj)
		{
			return objects[i];
		}
	}
	return NULL;
}

std::vector<Object*> Scene::GetObjectsInScene()
{
	return objects;
}
#pragma endregion

//								Handle objects
/*****************************************************************************/
#pragma region Handle Objects

void Scene::AddObject(Object* obj)
{
	objects.push_back(obj);
}

void Scene::DeleteObject(Object* obj)
{
	//Check if object exists
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] == obj)
		{
			//Swap with last position
			std::swap(objects[i], objects[objects.size() - 1]);
			Object* objectToDelete = objects[objects.size() - 1];
			//Remove it from vector
			objects.pop_back();

			//Delete object
			delete(objectToDelete);
			objectToDelete = NULL;
		}
	}
}
#pragma endregion

//								Others
/*****************************************************************************/
#pragma region Others

void Scene::Clear()
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] != NULL)
		{
			delete(objects[i]);
		}
	}
}
#pragma endregion

/*****************************************************************************/