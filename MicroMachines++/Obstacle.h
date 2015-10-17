#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Collection.h"
#include "DynamicObject.h"
#include "Vector3.h"


class Obstacle : public DynamicObject
{
public:
	Obstacle();
	Obstacle(double x, double y, double z);
	Obstacle(Vector3 _pos);
	virtual void draw();
};

#endif
