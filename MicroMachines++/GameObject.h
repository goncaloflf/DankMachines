#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Collection.h"
#include "Entity.h"
#include "Vector3.h"

class GameObject : public Entity
{
	public:

	GameObject(double _x, double _y, double _z);

	GameObject();

	GameObject(Vector3 _pos);

	~GameObject();

	virtual void draw();

	void print();

	virtual void update(double delta_t);

};

#endif