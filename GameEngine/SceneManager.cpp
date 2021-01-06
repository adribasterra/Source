#include "SceneManager.h"
#include "Object.h"

SceneManager::SceneManager()
{
	scenes = std::vector<Scene>();
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
	for (int i = 0; i < scenes.size(); i++)
	{
		if (&scenes[i] == scene)
		{
			//Set scene as current
			printf("Exist");
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
	return scene;
}


void SceneManager::Delete(Scene* scene)
{
	//Handle currentScene
	if (&scene == &currentScene) {
		if (scenes.size() > 0) {
			*currentScene = scenes[0];
		}
		else {
			currentScene = NULL;
		}
		printf("\n\nCurrent scene has been deleted.\n\n");
	}

	//Check if scene exists
	for (int i = 0; i < scenes.size(); i++)
	{
		//if (&scenes[i] == scene)
		{
			//Delete scene
			std::swap(scenes[i], scenes[scenes.size() - 1]);
			Scene* sceneToDelete = &scenes[scenes.size() - 1];
			scenes.pop_back();
			delete(sceneToDelete);
			sceneToDelete = NULL;
			printf("Scene has deleted successfully");
		}
	}
}

/*****************************************************************************/