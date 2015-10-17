#pragma once
#ifndef ROADSIDE_H
#define ROADSIDE_H
#include "Collection.h"
#include "StaticObject.h"
#include "Vector3.h"

class RoadSide : public StaticObject
{
public:
	RoadSide(double x, double y, double z);
	RoadSide();
	RoadSide(Vector3 pos);

	~RoadSide();

	void draw();

};

#endif
