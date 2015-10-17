#pragma once
#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "Collection.h"
#include "GameObject.h"
#include "Vector3.h"

class DynamicObject : public GameObject
{
protected:
	double _speed;

public:
	DynamicObject(double x, double y, double z);

	DynamicObject();

	DynamicObject(Vector3 pos);

	~DynamicObject();

	void update();

	void setSpeed(double speed);

	virtual void draw();

	double getSpeed();

};

#endif
