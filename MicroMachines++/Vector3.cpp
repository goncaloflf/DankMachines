#include "Vector3.h"
	 Vector3::Vector3(double x, double y, double z) {
		_x = x;
		_y = y;
		_z = z;
	}

	Vector3::Vector3(){}

	Vector3::~Vector3() {};

	double Vector3::getX() { return _x; }

	double Vector3::getY() { return _y;  }

	double Vector3::getZ() { return _z;  }

	void Vector3::setX(double x) { _x = x; }

	void Vector3::setY(double y) { _y = y;  }

	void Vector3::setZ(double z) { _z = z; }

	Vector3 Vector3::operatorPlus(Vector3 v) {
		_x = _x + v.getX();
		_y = _y + v.getY();
		_z = _z + v.getZ();
		return *this;
	}

	Vector3 Vector3::operatorMux(double m) {
		_x = _x * m;
		_y = _y * m;
		_z = _z * m;
		return *this;
	}

	Vector3 Vector3::operatorMinus( Vector3 v) {
		_x = _x - v.getX();
		_y = _y - v.getY();
		_z = _z - v.getZ();
		return *this;
	}

	bool Vector3::operatorEquals(Vector3 v1,Vector3 v2) {
		
		return ((v1.getX()==v2.getX()) && (v1.getY() == v2.getY()) && (v1.getZ() == v2.getZ()));
	}