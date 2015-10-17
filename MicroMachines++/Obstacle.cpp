#include "Obstacle.h"

	Obstacle::Obstacle(double x, double y, double z):DynamicObject(x,y,z) {
	}

	Obstacle::Obstacle(Vector3 _pos):DynamicObject(_pos) {
	}
	Obstacle::Obstacle(){}

	void Obstacle::draw() {}
