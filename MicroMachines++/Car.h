#pragma once
#ifndef CAR_H
#define CAR_H
#include "Collection.h"
#include "DynamicObject.h"

class Car : public DynamicObject
{
	bool _forward=false;
	bool _left=false;
	bool _right=false;
	bool _backward=false;
	bool _keyupFW=false;
	bool _keyupBW=false;
	bool _fwdTbwdF = false;

	float _accel = 0.0005f;
	float _back_speed=0.0f;
	float _max_speed = 0.05f;
	float _max_b_speed = 0.025f;
	float _angle = 0.0f;

	Vector3 _dof = Vector3(1,0,0);

public:
	double cenas;
	Car(double x, double y, double z);
	Car(Vector3 pos);
	Car();
	~Car();

	void draw();
	void setFWflag(bool _val);
	void setBWflag(bool _val);
	void setFlag(bool _val);
	void decreaseSpeed();
	void setBSpeed(double val);
	void setAngle(float _val);
	float getAngle();
	void setFW(bool _value);
	void setbW(bool _value);
	void setLF(bool _value);
	void setRG(bool _value);

	void setDoF(double x, double y, double z);

	void update(double delta_t);
};
#endif