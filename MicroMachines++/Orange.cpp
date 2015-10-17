#include "Orange.h"	
Orange::Orange(double x, double y, double z):Obstacle(x,y,z){}

	Orange::Orange(Vector3 _pos):Obstacle(_pos){}

	Orange::~Orange(){ }

	void Orange::draw(){

		glPushMatrix();
			glScalef(0.1, 0.1, 0.1);
			glTranslatef(0.f, 0.1f, 0.f);
			//LARANJA
			glPushMatrix(); //parte redonda
				glColor3f(1.0f, 0.5f, 0.0f);
				glRotatef(90, 1, 0, 0);
				glutSolidSphere(1.0f, 20.0f, 20.0f);
			glPopMatrix();
			glPushMatrix();
				glBegin(GL_LINES); //pauzinho
					glColor3f(0.0f, 0.5f, 0.0f);
					glVertex3f(0.0f, 1.0f, 0.0f);
					glVertex3f(0.8f, 1.5f, 0.0f);
				glEnd();
			glPopMatrix();
			glPushMatrix();
				glBegin(GL_POLYGON); //folha
					glColor3f(0.0f, 0.5f, 0.0f);
					glVertex3f(0.2f, 1.25f, 0.0f);
					glVertex3f(0.2f, 1.50f, 0.0f);
					glVertex3f(0.6f, 1.37f, 0.0f);
					glVertex3f(0.f, 1.5f, 0.0f);
				glEnd();
			glPopMatrix();
		glPopMatrix();
	}

	void Orange::update(){}

