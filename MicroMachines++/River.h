#pragma once
#ifndef RIVER_H
#define RIVER_H
#include "Collection.h"
#include "StaticObject.h"

class River : public StaticObject
{
	River(double x, double y, double z);

	~River();

	void draw();

};

#endif