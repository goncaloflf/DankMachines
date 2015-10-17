
#include "Entity.h"


	Entity::Entity(double x, double y, double z) {
		_pos = Vector3(x, y, z);
	}
	
	Entity::Entity(Vector3 pos) { 
		_pos = pos; 
	}

	Entity::Entity(){}

	Entity::~Entity() {}

	void Entity::setPosition(Vector3 v) {
		_pos = v;
	}

	void Entity::setPosition(double x, double y, double z) {
		_pos.setX(x);
		_pos.setY(y);
		_pos.setZ(z);
	}

	Vector3 Entity::getPosition() { return _pos; }

	void Entity::update(){}
