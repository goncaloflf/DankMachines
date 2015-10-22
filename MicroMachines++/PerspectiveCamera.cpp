#include "PerspectiveCamera.h"

	PerspectiveCamera::PerspectiveCamera(Vector3 pos, Vector3 up, Vector3 target, double near1, double far1, double fovy, double aspect):Camera(pos, up, target,near1,far1) {
		_fovy = fovy;
		_aspect = aspect;
	}

	PerspectiveCamera::PerspectiveCamera() : Camera(){}

	PerspectiveCamera::~PerspectiveCamera() {}

	double PerspectiveCamera::getFovy() { return _fovy; }

	void PerspectiveCamera::setFovy(double fovy) { _fovy = fovy; }

	double PerspectiveCamera::getAspect() { return _aspect; }

	void PerspectiveCamera::setAspect(double aspect) { _aspect = aspect; }

	void PerspectiveCamera::computeProjectionMatrix() {

		gluPerspective(_fovy, _aspect , _near1, _far1);
		gluLookAt(getPosition().getX(), getPosition().getY(), getPosition().getZ(), //eye 010
			_center.getX(), _center.getY(), _center.getZ(), //center 000
			_up.getX(), _up.getY(), _up.getZ());//up 001

	}

	void PerspectiveCamera::computeVisualizationMatrix() {}
