#include "Car.h"

	Car::Car(double x, double y, double z):DynamicObject(x,y,z) {
		_speed = 0;
	}

	Car::Car(Vector3 pos): DynamicObject(pos){
		_speed = 0;
	}

	Car::Car():DynamicObject(){
	}

	Car::~Car() {}
	void Car::setDoF(double x, double y, double z) {
		_dof.setX(x);
		_dof.setY(y);
		_dof.setX(z);
	}
	void Car::setFlag(bool _val) {
		_fwdTbwdF = _val;
	}
	void Car::setAngle(float _value) {
		_angle = _value;
	}
	float Car::getAngle() {
		return _angle;
	}
	void Car::draw() {
		//chassis completo
		glPushMatrix();
			glRotatef(_angle, 0, 1, 0);
			glScalef(0.1f, 0.1f, 0.1f);
			glPushMatrix();
				glColor3f(1.0f, 0.0f, 0.0f);
				//chassis baixo
				glPushMatrix();
					glScalef(2.0f, 0.5f, 0.5f);
					glutSolidCube(1);
				glPopMatrix();
				//telhado
				glPushMatrix();
					glTranslatef(-0.37f, 0.375f, 0.0f);
					glScalef(1.5f, 0.5f, 1.0f);
					glutSolidCube(0.5);
				glPopMatrix();
			glPopMatrix();
			//parabrisas carro
			glPushMatrix();
				glColor4f(0.0f, 0.0f, 1.0f, 0.4f);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glEnable(GL_BLEND);
				glBegin(GL_POLYGON);
					glVertex3f(0.0f, 0.5f, 0.25f);
					glVertex3f(0.0f, 0.5f, -0.25f);
					glVertex3f(0.75f, 0.25f, -0.25f);
					glVertex3f(0.75f, 0.25f, 0.25f);
				glEnd();
				glBegin(GL_POLYGON);
					glVertex3f(0.0f, 0.5f, 0.25f);
					glVertex3f(0.75f, 0.25f, 0.25f);
					glVertex3f(0.0f, 0.25f, 0.25f);
				glEnd();
				glBegin(GL_POLYGON);
					glVertex3f(0.0f, 0.5f, -0.25f);
					glVertex3f(0.75f, 0.25f, -0.25f);
					glVertex3f(0.0f, 0.25f, -0.25f);
				glEnd();
				//simbolo mercedes mas melhor
				glPushMatrix();
					glColor3f(0.0f, 1.0f, 0.0f);
					glTranslatef(1.0f, 0.3f, 0.0f);
					glutSolidTeapot(0.1);
				glPopMatrix();
			glPopMatrix();
			//RODAS
			glPushMatrix();
				glColor3f(1.0f, 1.0f, 0.5f);
				//roda1
				glPushMatrix();
					glTranslatef(0.6f, -0.1f, 0.3f);
					glutSolidTorus(0.1, 0.2, 20, 20);
				glPopMatrix();
				//roda2
				glPushMatrix();
					glTranslatef(0.6f, -0.1f, -0.3f);
					glutSolidTorus(0.1, 0.2, 20, 20);
				glPopMatrix();
				//roda3
				glPushMatrix();
					glTranslatef(-0.6f, -0.1f, 0.3f);
					glutSolidTorus(0.1, 0.2, 20, 20);
				glPopMatrix();
				//roda4
				glPushMatrix();
					glTranslatef(-0.6f, -0.1f, -0.3f);
					glutSolidTorus(0.1, 0.2, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	}
	void Car::setBSpeed(double val) {
		_back_speed = val;
	}
	void Car::setFWflag(bool _val) {
		_keyupFW = _val;
	}
	void Car::setBWflag(bool _val) {
		_keyupBW = _val;
	}
	//fds nem acredito
	void Car::update(double delta_t) {
		if (_backward == true && _forward == false) {
			if (_back_speed < _max_b_speed) 
				_back_speed += _accel;
				
				setPosition(
					getPosition().getX() - cos((_angle*3.14)/180)*_back_speed
					,0,
					getPosition().getZ() + sin((_angle*3.14) / 180)*_back_speed
					);		
		}

		if (_forward == true && _backward==false) {
			if (_speed < _max_speed) 
				_speed += _accel;
	
				setPosition(
					getPosition().getX() + cos((_angle*3.14) / 180)*_speed,
					0,
					getPosition().getZ() - sin((_angle*3.14) / 180)*_speed
					
					);
		}

		if (_left == true && _right==false) { 

			if (_speed != 0 || _back_speed!=0) {
				
				setAngle(getAngle() + 4);
			}
		}

		if (_right == true && _left==false) { 
			if (_speed != 0 || _back_speed!=0) {
				setDoF(_dof.getX()*sin((_angle*3.14) / 180), 0, _dof.getZ()*cos((_angle*3.14) / 180));
				setAngle(getAngle() - 4);
			}
		}

		if (_fwdTbwdF == true) {
			decreaseSpeed();
		}

		//printPosition(this);

	}
	void Car::decreaseSpeed() {

		if (_keyupBW==true) {
			if (_back_speed - _accel*3 >0)
				_back_speed -= _accel*3;
			else _back_speed = 0;

			setPosition(
				getPosition().getX() - cos((_angle*3.14) / 180)*_back_speed
				, 0,
				getPosition().getZ() + sin((_angle*3.14) / 180)*_back_speed
				);


		}

		if (_keyupFW==true) {
			if (_speed - _accel*3> 0)
				_speed -= _accel*3;
			else _speed = 0;

			setPosition(
				getPosition().getX() + cos((_angle*3.14) / 180)*_speed,
				0,
				getPosition().getZ() - sin((_angle*3.14) / 180)*_speed

				);
		
		}
		
	}
	void Car::setFW(bool _value) {
		_forward = _value;
	}
	void Car::setbW(bool _value) {
		_backward = _value;
	}
	void Car::setLF(bool _value) {
		_left = _value;
	}
	void Car::setRG(bool _value) {
		_right = _value;
	}

	