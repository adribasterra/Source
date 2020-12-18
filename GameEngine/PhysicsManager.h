#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "Object.h"
#include <vector>
/*
 * Physics Manager class
 */
class PhysicsManager: public Singleton<PhysicsManager>
{
	/*****************************************************************************/
	friend class Singleton<PhysicsManager>;
	/*****************************************************************************/

private:

	std::vector<SDL_Rect> colliders;
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
	void addCollider(SDL_Rect);
	void addCollider(float,float);

};