#include "Scene.h"
#include "SceneManager.h"
#include "Object.h"

//								Constructors
/*****************************************************************************/
Scene::Scene()
{
	//Initialize
	numObjects = 10;
	objects[numObjects];
}

Scene::~Scene()
{
	//Deallocate
	clearScene();
}

//								Main function
/*****************************************************************************/

void Scene::Update()
{
	//The “Update” function inside the Object Manager will probably be calling the “Update” function inside every Object.
}

//								Getters
/*****************************************************************************/
Object Scene::GetObject(Object* searchingObj)
{
	for (int i = 0; i < numObjects; i++)
	{
		if (&objects[i] == searchingObj)
		{
			return objects[i];
		}
	}
}

//								Setters
/*****************************************************************************/

void Scene::SetArraySize(int numObjects)
{
	this->numObjects = numObjects;
}


void Scene::AddObject(Object objToAdd)
{
	SetArraySize(numObjects++);
	objects[numObjects - 1] = objToAdd;
}

/*****************************************************************************/

void Scene::clearScene()
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
