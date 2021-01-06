#include "Scene.h"
#include "SceneManager.h"
#include "Object.h"

//								Constructors
/*****************************************************************************/
Scene::Scene()
{
	//Initialize
	objects = std::vector<Object>();
}

Scene::~Scene()
{
	for (int i = 0; i < objects.size(); i++)
	{
		delete(&objects[i]);
	}
	objects.clear();
}

//								Main function
/*****************************************************************************/

void Scene::Update()
{
	//Update of all Scene's objects
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i].Update();
	}
}

//								Getters
/*****************************************************************************/

Object* Scene::GetObject(int index)
{
	if (index < objects.size())
	{
		return &objects[index];
	}
	return NULL;
}

std::vector<Object>* Scene::GetObjectsInScene()
{
	return &objects;
}

#pragma region Commented

//								Setters
/*****************************************************************************/

/*void Scene::SetArraySize(int numObjects)
{
	this->numObjects = numObjects;
}*/

//								Objects
/*****************************************************************************/
/*
void Scene::CreateObject()
{
	Object* obj = new Object();
	objects.push_back(*obj);
}

void Scene::CreateObject(float x, float y)
{
	Object* obj = new Object(x, y);
	objects.push_back(*obj);
}

void Scene::CreateObject(float x, float y, float width, float height, float rotation, LTexture* texture)
{
	Object* obj = new Object(x, y, width, height, rotation, texture);
	objects.push_back(*obj);
}

void Scene::CreateObject(float x, float y, float width, float height, float rotation, LTexture* texture, SDL_Rect* rectangle)
{
	Object* obj = new Object(x, y, width, height, rotation, texture, rectangle);
	objects.push_back(*obj);
}

void Scene::CreateObject(float x, float y, float width, float height, float rotation, LTexture* texture, float* radius)
{
	Object* obj = new Object(x, y, width, height, rotation, texture, radius);
	objects.push_back(*obj);
}
*/

#pragma endregion

void Scene::AddObject(Object* obj)
{
	objects.push_back(*obj);
}


void Scene::DeleteObject(Object* obj)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (&objects[i] == obj)
		{
			std::swap(objects[i], objects[objects.size() - 1]);
			Object* objectToDelete = &objects[objects.size() - 1];
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
		if (&objects[i] != NULL)
		{
			delete(&objects[i]);
		}
	}
}
