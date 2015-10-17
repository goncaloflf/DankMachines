#pragma once
#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "Collection.h"
#include "GameObject.h"
#include "Vector3.h"

class StaticObject : public GameObject
{
public:
	StaticObject(double x, double y, double z);
	
	StaticObject();

	StaticObject(Vector3 pos);

	~StaticObject();
};

#endif