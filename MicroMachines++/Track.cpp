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
		glColor3f(0.0f, 0.7f, 0.0f);
		glTranslatef(0.0f, -0.05f, 0.0f);
		glScalef(4.0f, 0.0001f, 4.0f);
		glutSolidCube(1);
	glPopMatrix();
}
