#include "PerspectiveCamera.h"

	PerspectiveCamera::PerspectiveCamera(Vector3 pos, Vector3 up, Vector3 center, Vector3 at, double near1, double far1, double fovy, double aspect) {
		Camera(pos, up, center, at, near1, far1);
		_fovy = fovy;
		_aspect = aspect;
	}

	PerspectiveCamera::~PerspectiveCamera() { Camera::~Camera(); }

	double PerspectiveCamera::getFovy() { return _fovy; }

	void PerspectiveCamera::setFovy(double fovy) { _fovy = fovy; }

	double PerspectiveCamera::getAspect() { return _aspect; }

	void PerspectiveCamera::setAspect(double aspect) { _aspect = aspect; }

	void PerspectiveCamera::computePorjectionMatrix() {}

	void PerspectiveCamera::computeVisualizationMatrix() {}
