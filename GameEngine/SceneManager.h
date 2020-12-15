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
	Scene* scenes;				//Needs to be a vector
	Scene* currentScene;
	
	//Object* CreatedObject;

	// Private constructor to avoid more than one instance
	SceneManager() {};
	~SceneManager() {};

	/*****************************************************************************/

public:

	void ChangeScene(int);		//Pointer to next scene

	Scene* GetCurrentScene(void);
	void SetCurrentScene(Scene*);

	Scene* Create();
	void Delete(Scene*);		//Don't know if necessary or not

	Object* ReturnObject(void);

	/*****************************************************************************/

};
