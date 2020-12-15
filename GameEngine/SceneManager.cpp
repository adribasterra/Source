#include "SceneManager.h"
#include "Object.h"


//								Main function
/*****************************************************************************/

void SceneManager::ChangeScene(int id)
{
	//Check if that scene exists
	if (&(scenes[id]) != NULL && id < sizeof(scenes)) {
		(*currentScene) = scenes[id];
	}
}

//								Getters
/*****************************************************************************/

Scene* SceneManager::GetCurrentScene(void)
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

	return scene;
}


void SceneManager::Delete(Scene* scene)
{
	for (int i = 0; i < sizeof(scenes); i++) {
		if (&(scenes[i]) == scene) {
			//Hay que eliminar la instancia a esa clase Scene (nada de destructores Adriana por favor sé coherente)
		}
	}
}

/*****************************************************************************/