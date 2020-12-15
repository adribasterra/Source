#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "Object.h"

/*
 * Physics Manager class
 */
class PhysicsManager: public Singleton<PhysicsManager>
{
	/*****************************************************************************/
	friend class Singleton<PhysicsManager>;
	/*****************************************************************************/

private:

	SDL_Rect* colliders;	//Supuesto vector de colliders que no sé qué son
	// Private constructor to avoid more than one instance
	PhysicsManager() {};
	~PhysicsManager() {};

	bool RectCollisions(Object* obj1, Object* obj2);
	bool CircleCollisions(Object* obj1, Object* obj2);
	bool MixCollisions(Object* obj1, Object* obj2);
	double distanceSquared(int x1, int y1, int x2, int y2);

	/*****************************************************************************/
public:

	bool CheckCollisions(Object* obj1, Object* obj2);

};