#include "OrthogonalCamera.h"

	OrthogonalCamera::OrthogonalCamera(Vector3 pos, Vector3 up, Vector3 target, double near1, double far1, double left, double right, double bottom, double top):Camera(pos, up,target, near1, far1) {
		
		_left = left;
		_right = right;
		_bottom = bottom;
		_top = top;
	}

	void OrthogonalCamera::update() {}

	void OrthogonalCamera::computeProjectionMatrix() {
		
		glOrtho(_left, _right, _bottom, _top, _near1, _far1);
		gluLookAt(getPosition().getX(), getPosition().getY(), getPosition().getZ(), //eye 010
			_center.getX(), _center.getY(), _center.getZ(), //center 000
			_up.getX(), _up.getY(), _up.getZ());//up 001
		/*gluLookAt(0, 1, 0, //eye 010
			0, 0 ,0 , //center 000
			0, 0 ,1);//up 001*/
	}

	void OrthogonalCamera::computeVisualizationMatrix() {}

	
	OrthogonalCamera::OrthogonalCamera():Camera(){}

	OrthogonalCamera::~OrthogonalCamera() { }

	double OrthogonalCamera::getLeft() { return _left; }

	void OrthogonalCamera::setLeft(double left) { _left = left;  }

	double OrthogonalCamera::getRight() { return _right; }

	void OrthogonalCamera::setRight(double right) { _right = right; }

	double OrthogonalCamera::getBottom() { return _bottom; }

	void OrthogonalCamera::setBottom(double bottom) { _bottom = bottom; }

	double OrthogonalCamera::getTop() { return _top; }

	void OrthogonalCamera::setTop(double top) { _top = top; }


