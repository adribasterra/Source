#include "SceneManager.h"
#include "Object.h"


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
	scenes.push_back(*scene);
	return scene;
}


void SceneManager::Delete(Scene* scene)
{
	for (int i = 0; i < scenes.size(); i++) {
		if (&(scenes[i]) == scene) {
			//Hay que eliminar la instancia a esa clase Scene (nada de destructores Adriana por favor sé coherente)
		}
	}
}
void SceneManager::Delete(int index)
{
	if(index < scenes.size())
		scenes.erase(scenes.begin()+index);
}

/*****************************************************************************/