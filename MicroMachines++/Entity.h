#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Collection.h"
#include "Vector3.h"

class Entity {

	Vector3 _pos;
	
public:
	Entity(double x, double y, double z);

	Entity(Vector3 pos);

	Entity();
		
	~Entity();

	void setPosition(Vector3 v);

	void setPosition(double x, double y, double z);

	Vector3 getPosition();

	virtual void update();

};

#endif