#include "Track.h"



Track::Track()
{
}


Track::~Track()
{
}

void Track::draw() {
	//ground
	glPushMatrix();
		glColor3f(0.4f, 0.6f, 0.f);
		glTranslatef(0.0f, -0.05f, 0.0f);
		glScalef(4.0f, 0.0001f, 4.0f);
		glutSolidCube(1);
	glPopMatrix();
}
