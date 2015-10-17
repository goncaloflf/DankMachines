#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H

#include "Collection.h"
class Vector3 {

private:
	double _x;
	double _y;
	double _z;

public:
	Vector3(double x, double y, double z);
	Vector3();

	~Vector3();

	double getX();

	double getY();

	double getZ();

	void setX(double x);

	void setY(double y);

	void setZ(double z);

	bool operatorEquals(Vector3 v1, Vector3 v2);

	Vector3 operatorPlus(Vector3 v);

	Vector3 operatorMux(double m);

	Vector3 operatorMinus(Vector3 v);


};

#endif
