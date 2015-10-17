#ifndef BUTTER_H
#define BUTTER_H
#include "Collection.h"
#include "Obstacle.h"
#include "Vector3.h"

class Butter : public Obstacle
{
public:
	Butter(double x, double y, double z);

	Butter(Vector3 pos);

	void draw();

	void update();

};
#endif
