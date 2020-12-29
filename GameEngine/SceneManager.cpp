#include "SceneManager.h"
#include "Object.h"

SceneManager::SceneManager()
{
	numberOfScenes = 10;
	scenes = std::vector<Scene>(numberOfScenes);
}
//								Main function
/*****************************************************************************/

void SceneManager::ChangeScene(int id)
{
	//Check if that scene exists
	if (id < scenes.size()) {
		currentScene = &scenes[id];
	}
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
	currentScene = scene;
}


/*****************************************************************************/

Scene* SceneManager::Create() {

	Scene* scene = new Scene();

	//Add it to the scenes vector
	scenes.push_back(*scene);
	return scene;
}


void SceneManager::Delete(Scene* scene)
{
	for (int i = 0; i < scenes.size(); i++)
	{
		if (&scenes[i] == scene)
		{
			std::swap(scenes[i], scenes[scenes.size() - 1]);
			Scene* sceneToDelete = &scenes[scenes.size() - 1];
			scenes.pop_back();
			delete(sceneToDelete);
			sceneToDelete = NULL;
		}
	}
	printf("Scene has deleted");
}

/*****************************************************************************/