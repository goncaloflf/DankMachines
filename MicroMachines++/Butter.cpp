#include "Butter.h"

Butter::Butter(double x, double y, double z):Obstacle(x,y,z){}

Butter::Butter(Vector3 pos):Obstacle(pos){}

void Butter::update() {

}

void Butter::draw() {
		glPushMatrix();
			
			glScalef(0.1f, 0.2f, 0.1f);
			glPushMatrix();
				glColor3f(1.f,1.f,1.f);
				glScalef(1.2f, 0.5f, 1.2f);
				glutSolidCube(1);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0f, 0.26f, 0.0f);
				glScalef(0.8f, 1.f, 0.8f);
				glColor3f(0.f, 1.f, 0.f);
				glBegin(GL_POLYGON);
					glVertex3f(-1.0f, 0.0f, 1.0f);
					glVertex3f(-1.0f, 0.0f, -1.0f);
					glVertex3f(1.0f, 0.0f, -1.0f);
					glVertex3f(1.0f, 0.0f, 1.0f);
				glEnd();
			glPopMatrix();
		glPopMatrix();
}
