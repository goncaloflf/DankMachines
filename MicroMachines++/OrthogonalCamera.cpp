#include "OrthogonalCamera.h"

	OrthogonalCamera::OrthogonalCamera(Vector3 pos, Vector3 up, Vector3 center, Vector3 at, double near1, double far1, double left, double right, double bottom, double top) {
		Camera(pos, up, center, at, near1, far1);
		_left = left;
		_right = right;
		_bottom = bottom;
		_top = top;
	}

	OrthogonalCamera::~OrthogonalCamera() { Camera::~Camera(); }

	double OrthogonalCamera::getLeft() { return _left; }

	void OrthogonalCamera::setLeft(double left) { _left = left;  }

	double OrthogonalCamera::getRight() { return _right; }

	void OrthogonalCamera::setRight(double right) { _right = right; }

	double OrthogonalCamera::getBottom() { return _bottom; }

	void OrthogonalCamera::setBottom(double bottom) { _bottom = bottom; }

	double OrthogonalCamera::getTop() { return _top; }

	void OrthogonalCamera::setTop(double top) { _top = top; }

	void OrthogonalCamera::update() {}

	void OrthogonalCamera::computeProjectionMatrix() {}

	void OrthogonalCamera::computeVisualizationMatrix() {}
