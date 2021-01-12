#include "Scene.h"
#include "SceneManager.h"
#include "Object.h"

//								Constructors
/*****************************************************************************/
Scene::Scene()
{
	//Initialize
	objects = std::vector<Object*>();
	objects.reserve(10);
}

Scene::~Scene()
{
	for (int i = 0; i < objects.size(); i++)
	{
		delete(objects[i]);
	}
	objects.clear();
}

//								Main function
/*****************************************************************************/

void Scene::Update(float dt)
{
	//Update of all Scene's objects
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt);
	}
}

//								Getters
/*****************************************************************************/

Object* Scene::GetObject(int index)
{
	if (index < objects.size())
	{
		return objects[index];
	}
	return NULL;
}

std::vector<Object*> Scene::GetObjectsInScene()
{
	return objects;
}

void Scene::AddObject(Object* obj)
{
	objects.push_back(obj);
}

// TODOOOOOOO Revisar
void Scene::DeleteObject(Object* obj)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i] == obj)
		{
			std::swap(objects[i], objects[objects.size() - 1]);
			Object* objectToDelete = objects[objects.size() - 1];
			objects.pop_back();
			delete(objectToDelete);
			objectToDelete = NULL;
		}
	}
}

/*****************************************************************************/

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
