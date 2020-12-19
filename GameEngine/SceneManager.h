#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "Scene.h"
#include <vector>
/*
 * Scene Manager class
 */
class SceneManager : public Singleton<SceneManager>
{
	/*****************************************************************************/
	friend class Singleton<SceneManager>;
	/*****************************************************************************/

private:

	// Scenes
	std::vector<Scene> scenes;
	Scene* currentScene;
	int numberOfScenes;
	//Object* CreatedObject;

	// Private constructor to avoid more than one instance
	SceneManager() {};
	~SceneManager() {};

	/*****************************************************************************/
public:

	void ChangeScene(int);		//Pointer to next scene
	
	//Getters & setters
	Scene* GetCurrentScene(void);
	void SetCurrentScene(Scene*);

	Scene* Create();
	void Delete(Scene*);		//Don't know if necessary or not

};
