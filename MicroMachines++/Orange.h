#pragma once
#ifndef ORANGE_H
#define ORANGE_H
#include "Collection.h"
#include "Obstacle.h"
#include "Vector3.h"

class Orange : public Obstacle
{
public:
	Orange(double x, double y, double z);

	Orange(Vector3 _pos);

	~Orange();

	void draw();

	void update();

};


#endif
