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

	std::vector<Scene*> scenes;		//Scenes
	Scene* currentScene;			//Scene to renderize & update

	//Private constructor to avoid more than one instance
	SceneManager();
	~SceneManager();

	/*****************************************************************************/
public:

	Scene* Create();
	void Delete(Scene*);

	//Getters & setters
	Scene* GetCurrentScene();
	void SetCurrentScene(Scene*);	//Changes renderized & updated scene

	/*****************************************************************************/
};
