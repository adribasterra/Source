#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "Scene.h"

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
	Scene* scenes;
	Scene* currentScene;

	// Private constructor to avoid more than one instance
	SceneManager() {};
	~SceneManager() {};

	/*****************************************************************************/

public:

	void ChangeScene(int);	//Pointer to next scene

	Scene* GetCurrentScene(void);

	void Add(Scene*);		//Don't know if there's need of pointer or it just adds it

	void Delete(Scene*);		//Don't know if necessary or not 

	/*****************************************************************************/

};
