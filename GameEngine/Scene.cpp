#include "Scene.h"
#include "SceneManager.h"
#include "Object.h"

//								Constructors
/*****************************************************************************/
Scene::Scene()
{
	//Initialize
	numObjects = 10;
	objects = std::vector<Object>(numObjects);
}

Scene::~Scene()
{
	free(&numObjects);
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
	//The “Update” function inside the Object Manager will probably be calling the “Update” function inside every Object.
	for (int i = 0; i < numObjects; i++)
	{
		objects[i].Update();
	}
}

//								Getters
/*****************************************************************************/

Object* Scene::GetObject(int index)
{
	/*for (int i = 0; i < numObjects; i++)
	{
		if (objects[i] == searchingObj)
		{
			return objects[i];
		}
	}*/
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

//								Setters
/*****************************************************************************/

/*void Scene::SetArraySize(int numObjects)
{
	this->numObjects = numObjects;
}*/

//								Objects
/*****************************************************************************/

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
	for (int i = 0; i < numObjects; i++)
	{
		if (&objects[i] != NULL)
		{
			//objects[i] = NULL;
			numObjects--;
		}
	}
}
