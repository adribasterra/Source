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

	std::vector<Scene*> scenes;		// Scenes
	Scene* currentScene;			// Scene to renderize

	// Private constructor to avoid more than one instance
	SceneManager();
	~SceneManager() {};

	/*****************************************************************************/
public:

	//Getters & setters
	Scene* GetCurrentScene();
	void SetCurrentScene(Scene*);	//Changes renderized scene

	Scene* Create();
	void Delete(Scene*);			//Don't know if necessary or not, destructor??

};
