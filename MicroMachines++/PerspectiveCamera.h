#pragma once
#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H
#include "Collection.h"
#include "Camera.h"
#include "Vector3.h"


class PerspectiveCamera : public Camera
{
protected:
	double _fovy;
	double _aspect;
public:
	PerspectiveCamera(Vector3 pos, Vector3 up, Vector3 target, double near, double far, double fovy, double aspect);

	~PerspectiveCamera();

	double getFovy();

	void setFovy(double fovy);

	double getAspect();

	void setAspect(double aspect);

	void computePorjectionMatrix();

	void computeVisualizationMatrix();
};

#endif