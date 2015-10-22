#pragma once
#ifndef ORTHOGONALCAMERA_H
#define ORTHOGONALCAMERA_H
#include "Collection.h"
#include "Camera.h"
#include "Vector3.h"

class OrthogonalCamera : public Camera
{
protected:
	double _left;
	double _right;
	double _bottom;
	double _top;

public:
	OrthogonalCamera(Vector3 pos, Vector3 up, Vector3 target, double near1, double far1, double left, double right, double bottom, double top);

	OrthogonalCamera();

	~OrthogonalCamera();

	double getLeft();

	void setLeft(double left);

	double getRight();

	void setRight(double right);

	double getBottom();

	void setBottom(double bottom);

	double getTop();

	void setTop(double top);

	void update();

	void computeProjectionMatrix();

	void computeVisualizationMatrix();

};

#endif
