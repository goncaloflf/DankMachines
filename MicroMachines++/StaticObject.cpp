#include "StaticObject.h"
	StaticObject::StaticObject(double x, double y, double z):GameObject(x,y,z){}

	StaticObject::StaticObject():GameObject(){}

	StaticObject::StaticObject(Vector3 pos):GameObject(pos){}

	StaticObject::~StaticObject() {}
