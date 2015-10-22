#include "GameObject.h"

	GameObject::GameObject(double x, double y, double z):Entity(x,y,z) {}

	GameObject::GameObject():Entity(){}

	GameObject::GameObject(Vector3 _pos):Entity(_pos){}

	GameObject::~GameObject() {}

	void GameObject::draw() {}

	void GameObject::update(double delta_t) {}

	



