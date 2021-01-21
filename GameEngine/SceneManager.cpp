#include "SceneManager.h"
#include "Object.h"

//								Constructors
/*****************************************************************************/
#pragma region Constructors

SceneManager::SceneManager()
{
	scenes = std::vector<Scene*>();
	scenes.reserve(10);
	currentScene = NULL;
}

SceneManager::~SceneManager()
{
	for (int i = 0; i < scenes.size(); i++)
	{
		//Delete all scenes from vector
		this->Delete(scenes[i]);
	}
	scenes.clear();
}
#pragma endregion

//								Getters
/*****************************************************************************/
#pragma region Getters

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}
#pragma endregion

//								Setters
/*****************************************************************************/
#pragma region Setters

void SceneManager::SetCurrentScene(Scene* scene)
{
	//Check if that scene exists
	for (int i = 0; i < scenes.size(); i++)
	{
		if (scenes[i] == scene)
		{
			//Set scene as current
			currentScene = scene;
			return;
		}
	}
	printf("ERROR. That scene does not exist in Scene Manager!\n");
}
#pragma endregion

//								Main functions
/*****************************************************************************/
#pragma region Main functions

Scene* SceneManager::Create()
{
	Scene* scene = new Scene();

	//Add it to the scenes vector
	scenes.push_back(scene);
	return scene;
}

void SceneManager::Delete(Scene* scene)
{
	//Handle currentScene
	if (scene == currentScene) {
		if (scenes.size() > 0) {
			//Set next scene as current
			currentScene = scenes[0];
		}
		else {
			currentScene = NULL;
		}
		printf("Current scene has been deleted.\n");
	}

	//Check if scene exists
	for (int i = 0; i < scenes.size(); i++)
	{
		if (scenes[i] == scene)
		{
			//Swap with last position
			std::swap(scenes[i], scenes[scenes.size() - 1]);
			Scene* sceneToDelete = scenes[scenes.size() - 1];
			//Remove it from vector
			scenes.pop_back();

			//Delete scene
			delete(sceneToDelete);
			sceneToDelete = NULL;
			printf("Scene deleted successfully.\n");
		}
	}
}
#pragma endregion

/*****************************************************************************/