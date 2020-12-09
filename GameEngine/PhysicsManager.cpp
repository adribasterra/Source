#include "PhysicsManager.h"


//								Main function
/*****************************************************************************/

bool PhysicsManager::CheckCollisions(Object* obj1, Object* obj2)
{
    if (obj1->GetTypeCollision() == colliderTypes::rect && obj2->GetTypeCollision() == colliderTypes::rect)
    {
        return RectCollisions(obj1, obj2);
    }
    else if (obj1->GetTypeCollision() == colliderTypes::circle && obj2->GetTypeCollision() == colliderTypes::circle)
    {
        return CircleCollisions(obj1, obj2);
    }
    else if (obj1->GetTypeCollision() == colliderTypes::circle && obj2->GetTypeCollision() == colliderTypes::rect)
    {
        return MixCollisions(obj1, obj2);
    }
    else if (obj1->GetTypeCollision() == colliderTypes::rect && obj2->GetTypeCollision() == colliderTypes::circle)
    {
        return MixCollisions(obj2, obj1);
    }
}

//								Collisions
/*****************************************************************************/

bool PhysicsManager::RectCollisions(Object* obj1, Object* obj2)
{
    //Calculate the sides of rect A
    float leftA   = obj1->GetX();
    float rightA  = obj1->GetX() + obj1->GetCollider()->w;
    float topA    = obj1->GetY();
    float bottomA = obj1->GetY() + obj1->GetCollider()->h;

    //Calculate the sides of rect B
    float leftB   = obj2->GetX();
    float rightB  = obj2->GetX() + obj2->GetCollider()->w;
    float topB    = obj2->GetY();
    float bottomB = obj2->GetY() + obj2->GetCollider()->h;

    //If any of the sides from A are outside of B
    if (bottomA <= topB ||
        topA >= bottomB ||
        rightA <= leftB ||
        leftA >= rightB)
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

/*****************************************************************************/

bool PhysicsManager::CircleCollisions(Object* obj1, Object* obj2)
{
    //Calculate total radius squared
    float totalRadiusSquared = obj1->GetRadius() + obj2->GetRadius();
    totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

    //If the distance between the centers of the circles is less than the sum of their radii
    if (distanceSquared(obj1->GetX(), obj1->GetY(), obj2->GetX(), obj2->GetY()) < (totalRadiusSquared))
    {
        return true;    //The circles have collided
    }

    return false;
}

/*****************************************************************************/

bool PhysicsManager::MixCollisions(Object* obj1, Object* obj2)
{
    //Closest point on collision box
    float pointX, pointY;

    //Find closest X offset
    if (obj1->GetX() < obj2->GetX())
    {
        pointX = obj2->GetCollider()->x;
    }
    else if (obj1->GetX() > obj2->GetX() + obj2->GetCollider()->w)
    {
        pointX = obj2->GetX() + obj2->GetCollider()->w;
    }
    else
    {
        pointX = obj1->GetX();
    }

    //Find closest Y offset
    if (obj1->GetY() < obj2->GetY())
    {
        pointY = obj2->GetY();
    }
    else if (obj1->GetY() > obj2->GetY() + obj2->GetCollider()->h)
    {
        pointY = obj2->GetY() + obj2->GetCollider()->h;
    }
    else
    {
        pointY = obj1->GetY();
    }

    //If the closest point is inside the circle
    double radius = (double) obj1->GetRadius() * obj1->GetRadius();
    if (distanceSquared(obj1->GetX(), obj1->GetY(), pointX, pointY) < radius)
    {
        return true;    //This box and the circle have collided
    }

    return false;
}

double PhysicsManager::distanceSquared(int x1, int y1, int x2, int y2)
{
    double deltaX = (double) x2 - x1;
    double deltaY = (double) y2 - y1;
    double distance = deltaX * deltaX + deltaY * deltaY;
    return distance;
}

/*****************************************************************************/

