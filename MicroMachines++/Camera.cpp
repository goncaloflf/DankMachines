#include "Camera.h"

	Camera::Camera(Vector3 pos, Vector3 up,Vector3 target, double near1, double far1):Entity(pos) {
		Vector3 _dirVector;
		_near1 = near1;
		_far1 = far1;
		//receives _up vector that up vector pointing upwards, YY direction
		/*
		_up = up;
		_center = target;
		_rightVector = _center.crossProduct(_up);
		*/
		
		_center = target;
		_dirVector = pos.operatorMinus(target);
		_rightVector = _dirVector.crossProduct(up);
		_up = _dirVector.crossProduct(_rightVector);
		
	}

	Camera::Camera(){}

	Camera::~Camera() { }

	Vector3 Camera::getCenter() { return _center; }

	void Camera::setCenter(Vector3 center) { _center = center; }

	Vector3 Camera::getUp() { return _up; }

	void Camera::setUp(Vector3 up) { _up = up; }

	double Camera::getNear() { return _near1; }

	void Camera::setNear(double near1) { _near1 = near1; }

	double Camera::getFar() { return _far1; }

	void Camera::setFar(double far1) { _far1 = far1; }

	void Camera::update() {}

	void Camera::computeProjectionMatrix() {}

	void Camera::computeVisualizationMatrix() {}


