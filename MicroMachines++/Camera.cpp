#include "Camera.h"

	Camera::Camera(Vector3 pos, Vector3 up,Vector3 center, Vector3 at, double near1, double far1) {
		//puto wtf
		Entity::Entity(pos);
		_near1 = near1;
		_far1 = far1;
		_up = up;
		_center = center;
		_at = at;
	}

	Camera::Camera(){}

	Camera::~Camera() { Entity::~Entity(); }

	Vector3 Camera::getAt() { return _at; }

	void Camera::setAt(Vector3 at) { _at = at; }

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


