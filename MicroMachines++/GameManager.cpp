#include "GameManager.h"
static GameManager* _currentInstance;
//fix physics
//fix destructors in gamemaneger

//FPS display
//logger
//nao gosto do carro


GameManager::GameManager(){
	_printer = Printer();
}

GameManager::~GameManager() {
	for each (Camera camera in _cameras) {
		camera.~Camera();
	}
}
void GameManager::addGameObject(Car* _obj){
	_cars.push_back(_obj);
}
void GameManager::addGameObject(RoadSide* _obj) {
	_track.push_back(_obj);
}
void GameManager::addGameObject(Butter* _obj){
	_butters.push_back(_obj);
}
void GameManager::addGameObject(Orange* _obj){
	_oranges.push_back(_obj);
}
void GameManager::addGameObject(Track* _obj) {
	_ground = _obj;
}
void GameManager::displayCallback() {
	_currentInstance->display();
}
void GameManager::reshapeCallback(int x, int y) {
	_currentInstance->myReshape(x, y);
}
void GameManager::specialCallback(int key, int x, int y) {
	_currentInstance->specialKeys(key, x, y);
}
void GameManager::specialUpCallback(int key, int x, int y) {
	_currentInstance->specialUpKeys(key, x, y);
}
void GameManager::keypressCallback(unsigned char key, int x, int y) {
	_currentInstance->keyPressed(key, x, y);
}
void GameManager::timerCallback(int i) {
	_currentInstance->onTimer();

}
void GameManager::setupCallbacks() {
	_currentInstance = this;
}
Camera GameManager::getCamera(int i) { 
	return _cameras[i];
}

void GameManager::onTimer() {
	update();
	display();
	glutPostRedisplay();
	glutTimerFunc(DELTA_T, timerCallback, 0);
}

void GameManager::idle() {}

void GameManager::update() {

	for each(Car *obj in _cars) {
		obj->update(DELTA_T);
	}

	for each(Orange *obj in _oranges) {
		obj->update();
	}

	for each(Butter *obj in _butters) {
		obj->update();
	}
	
}

void GameManager::myReshape(GLsizei w, GLsizei h) {
	float xmin = -2., xmax = 4., ymin = -1., ymax = 3.;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;
	if (aspect > ratio)
		glViewport((w - h*ratio) / 2, 0, h*ratio, h);
	else
		glViewport(0, (h - w / ratio) / 2, w, w / ratio);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
	gluLookAt(0, 1, 0, //eye
			  0, 0, 0, //center
			  0, 0, 1);//up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GameManager::display() {
	
	//Reset window and color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0.5,0.8,0.2);
	//Make sure matrix is clear
	glLoadIdentity();

	//Link rotation to defined variable
	glRotatef(rotate_x, 1.0f, 0.0f, 0.0f);
	glRotatef(rotate_y, 0.0f, 1.0f, 0.0f);

	//Toggle wireframe mode
	if (debug_mode == true) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		
	//SETUP FINNISH
	//DRAWING PHASE
	
	for each(Car *obj in _cars) {
		glPushMatrix();
			glTranslatef(obj->getPosition().getX(), obj->getPosition().getY(), obj->getPosition().getZ());
			obj->draw();
			_printer.printPosition(obj);
		glPopMatrix();
	}

	for each(Orange *obj in _oranges) {
		glPushMatrix();
			glTranslatef(obj->getPosition().getX(), obj->getPosition().getY(), obj->getPosition().getZ());
			obj->draw();
		glPopMatrix();
	}

	for each(Butter *obj in _butters) {
		glPushMatrix();
			glTranslatef(obj->getPosition().getX(), obj->getPosition().getY(), obj->getPosition().getZ());
			obj->draw();
		glPopMatrix();
	}

	for each(RoadSide *obj in _track) {
		float _angle = 0;
		float _inner_radius = 1.f;
		float _outter_radius = 1.8f;

		while (_angle < 360) {
			glPushMatrix();
				glRotatef(_angle, 0, 1, 0);
				glTranslatef(0, 0, _inner_radius);
				obj->draw();
			glPopMatrix();
			_angle += 8.f;
		}
		_angle = 0;
		while (_angle < 360) {
			glPushMatrix();
				glRotatef(_angle, 0, 1, 0);
				glTranslatef(0, 0, _outter_radius);
				obj->draw();
			glPopMatrix();
			_angle += 4.f;
		}
	}

	_ground->draw();

	//FINISH DRAWING PHASE
	//FLUSH OPENGL CONTEXT
	glFlush();
	glutSwapBuffers();

}

void GameManager::setDebugMode(bool _val) {
	debug_mode = _val;
}

void GameManager::keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case (int('a')) :
		if (debug_mode == true) setDebugMode(false);
		else setDebugMode(true);
		break;
	case int('d'):
		rotate_x -= 5;
		break;
	case int('e'):
		rotate_x += 5;
		break;
	case int('s'):
		rotate_y -= 5;
		break;
	case int('f'):
		rotate_y += 5;
		break;
	}
}

void GameManager::specialKeys(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_F8 :
		_scaling_factor -= 0.1f;
		break;

	case GLUT_KEY_F7:
		_scaling_factor += 0.1f;
		break;
	case GLUT_KEY_DOWN:
		_cars[0]->setbW(true);
		_cars[0]->setFlag(false);
		break;
	case GLUT_KEY_UP:
		_cars[0]->setFW(true);
		_cars[0]->setFlag(false);
		break;
	case GLUT_KEY_LEFT:
		_cars[0]->setLF(true);
		break;
	case GLUT_KEY_RIGHT:
		_cars[0]->setRG(true);
		break;
	case GLUT_KEY_END:
		exit(1);
	}

}

void GameManager::specialUpKeys(int key,int x, int y) {
	switch (key) {
	case GLUT_KEY_DOWN:
		_cars[0]->setbW(false);
		_cars[0]->setBWflag(true);
		_cars[0]->setFlag(true);
		break;
	case GLUT_KEY_UP:
		_cars[0]->setFW(false);
		_cars[0]->setFWflag(true);
		_cars[0]->setFlag(true);
		break;
	case GLUT_KEY_LEFT:
		_cars[0]->setLF(false);
		break;
	case GLUT_KEY_RIGHT:
		_cars[0]->setRG(false);
		break;
	}
}

void GameManager::init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 400);
	glutCreateWindow("MicroFails");
	glEnable(GL_DEPTH_TEST);

	GameManager::setupCallbacks();
	glutReshapeFunc(GameManager::reshapeCallback);
	glutSpecialFunc(GameManager::specialCallback);
	glutSpecialUpFunc(GameManager::specialUpCallback);
	glutKeyboardFunc(GameManager::keypressCallback);
	glutTimerFunc(15, GameManager::timerCallback, 0);
	glutDisplayFunc(GameManager::displayCallback);
	glutMainLoop();

}
