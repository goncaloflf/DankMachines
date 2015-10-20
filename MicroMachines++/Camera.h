#ifndef CAMERA_H
#define CAMERA_H
#include "Collection.h"
#include "Vector3.h"
#include "Entity.h"


class Camera : public Entity
{
protected:
	double _near1;
	double _far1;
	Vector3 _up;
	Vector3 _center;
	Vector3 _right;

public:

	Camera(Vector3 pos, Vector3 up, Vector3 target, double near1, double far1);

	Camera();

	~Camera();

	Vector3 getCenter();

	void setCenter(Vector3 center);


	Vector3 getUp();

	void setUp(Vector3 up);

	double getNear();

	void setNear(double near);

	double getFar();

	void setFar(double far);

	void update();

	void computeProjectionMatrix();

	void computeVisualizationMatrix();
};

#endif