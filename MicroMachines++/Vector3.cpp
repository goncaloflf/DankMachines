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
		Vector3 _newVector;
		_newVector.setX(_x + v.getX());
		_newVector.setY(_y + v.getY());
		_newVector.setZ(_z + v.getZ());
		return _newVector;
	}

	Vector3 Vector3::operatorMux(double m) {
		Vector3 _newVector;
		_newVector.setX(_x*m);
		_newVector.setY(_y*m);
		_newVector.setZ(_z*m);
		return _newVector;
	}

	//void-> vector.minus alter vector
	Vector3 Vector3::operatorMinus( Vector3 v) {
		Vector3 _newVector;
		_newVector.setX(_x - v.getX());
		_newVector.setY(_y - v.getY());
		_newVector.setZ(_z - v.getZ());
		return _newVector;
	}

	void Vector3::normalizeVec() {
		double _norm = getNorm();
		setX(getX() / _norm);
		setY(getY() / _norm);
		setZ(getZ() / _norm);
	}

	double Vector3::getNorm() {
		return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
	}

	Vector3 Vector3::crossProduct(Vector3 _v) {
		Vector3 _newVector;
		_newVector.setX(getY()*_v.getZ() - getZ()*_v.getY());
		_newVector.setY((getX()*_v.getZ() - _v.getX()*getZ())*-1);
		_newVector.setZ(getX()*_v.getY() - getY()*_v.getX());
		return _newVector;
	}

	bool Vector3::operatorEquals(Vector3 v1,Vector3 v2) {
		
		return ((v1.getX()==v2.getX()) && (v1.getY() == v2.getY()) && (v1.getZ() == v2.getZ()));
	}