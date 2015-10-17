#include "DynamicObject.h"



	DynamicObject::DynamicObject(double x, double y, double z):GameObject(x,y,z) {}
	DynamicObject::DynamicObject(Vector3 pos):GameObject(pos) {}
	DynamicObject::DynamicObject():GameObject(){}
	DynamicObject::~DynamicObject() { 
	}

	void DynamicObject::update() {}

	void DynamicObject::draw(){ }

	void DynamicObject::setSpeed(double speed){
		_speed = speed;
	}

	double DynamicObject::getSpeed() { return _speed; }




