#include "RoadSide.h"

	RoadSide::RoadSide(double x, double y, double z):StaticObject(x,y,z){}

	RoadSide::RoadSide():StaticObject(){}

	RoadSide::RoadSide(Vector3 pos):StaticObject(pos){}

	RoadSide::~RoadSide(){}

	void RoadSide::draw() {
		glPushMatrix();
			glScalef(0.1f, 0.1f, 0.1f);
			glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ() );
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glColor3f(1,1,0);
			glutSolidTorus(0.2f, 0.4f, 20.0f, 20.0f);
		glPopMatrix();

	}