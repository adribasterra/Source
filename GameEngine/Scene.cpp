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
	//Deallocate
	Clear();
}

//								Main function
/*****************************************************************************/

void Scene::Update()
{
	//The “Update” function inside the Object Manager will probably be calling the “Update” function inside every Object.
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
	return &objects[index];
}

//								Setters
/*****************************************************************************/

/*void Scene::SetArraySize(int numObjects)
{
	this->numObjects = numObjects;
}*/


void Scene::AddObject(Object objToAdd)
{
	//SetArraySize(numObjects++);
	//objects[0] = &objToAdd;
	objects.push_back(objToAdd);
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
