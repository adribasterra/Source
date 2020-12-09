#include "SceneManager.h"


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

/*****************************************************************************/

void SceneManager::Add(Scene* scene)
{

}


void SceneManager::Delete(Scene* scene)
{
	for (int i = 0; i < sizeof(scenes); i++) {
		if (&(scenes[i]) == scene) {
			//Hay que eliminar la instancia a esa clase Scene (nada de destructores Adriana por favor s� coherente)
		}
	}
}

/*****************************************************************************/
