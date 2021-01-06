#include "SceneManager.h"
#include "Object.h"

SceneManager::SceneManager()
{
	numScenes = 0;
	scenes = std::vector<Scene>(numScenes);
	currentScene = NULL;
}

//								Getters
/*****************************************************************************/

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}

//								Setters
/*****************************************************************************/

void SceneManager::SetCurrentScene(Scene* scene)
{
	//Check if that scene exists
	//for (int i = 0; i < scenes.size(); i++)
	{
		//if (&scenes[i] == scene)
		{
			//Set scene as current
			currentScene = scene;
			return;
		}
	}
	printf("\n\nERROR. That scene does not exists in Scene Manager!\n\n");
}

//								Main func
/*****************************************************************************/

Scene* SceneManager::Create() {

	Scene* scene = new Scene();

	//Add it to the scenes vector
	scenes.push_back(*scene);
	numScenes++;
	return scene;
}


void SceneManager::Delete(Scene* scene)
{
	for (int i = 0; i < scenes.size(); i++)
	{
		//if (&scenes[i] == scene)
		{
			std::swap(scenes[i], scenes[scenes.size() - 1]);
			delete(&scenes[scenes.size() - 1]);
			scenes.pop_back();
			printf("Scene has deleted successfully");
		}
	}
}

/*****************************************************************************/