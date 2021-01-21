#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "Object.h"
#include <vector>

/**
 * Physics Manager class
 */
class PhysicsManager : public Singleton<PhysicsManager>
{
	/*****************************************************************************/
	friend class Singleton<PhysicsManager>;
	/*****************************************************************************/

private:

	std::vector<SDL_Rect*> rectColliders;
	std::vector<float*> circleColliders;

	// Private constructor to avoid more than one instance
	PhysicsManager();
	~PhysicsManager();

	//Calculate collisions
	bool CategorizeCollisions(Object* obj1, Object* obj2);
	bool RectCollisions(Object* obj1, Object* obj2);
	bool CircleCollisions(Object* obj1, Object* obj2);
	bool MixCollisions(Object* obj1, Object* obj2);
	double DistanceSquared(int x1, int y1, int x2, int y2);

	/*****************************************************************************/
public:

	void CheckCollisions();

	SDL_Rect* LoadCollider(SDL_Rect*);
	float* LoadCollider(float*);

	/*****************************************************************************/
};