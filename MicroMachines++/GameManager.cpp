#include "GameManager.h"
static GameManager* _currentInstance;
//fix physics
//fix destructors in gamemaneger
//implement cameras - study that shit
//implement lights
//fix cheerios
//textures?
//moving wheels according to DoF
//collisions -> event handler
//fix game loop with DELTA_T
//parent and child objects -> move table, move cheerios
//sera realmente bom ter as translaçoes no draw? apply transformation ?

//FPS display
//nao gosto do carro


GameManager::GameManager(){
	_printer = Printer();
}

GameManager::~GameManager() {}


void GameManager::onTimer() {
	//calcFPS();
	update();
	display();
	glutPostRedisplay();
	glutTimerFunc(DELTA_T, timerCallback, 0);
}

void GameManager::calcFPS() {
	static char _windowTitle[20];
	static int frame = 0, time, timebase = 0;

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(_windowTitle,"DankMachines %d", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
	glutSetWindowTitle(_windowTitle);
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
}

void GameManager::display() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	_currentCamera->computeProjectionMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Reset window and color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.f,0.75f,1.f,0.f);
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
		glPushMatrix();
			glTranslatef(obj->getPosition().getX(), obj->getPosition().getY(), obj->getPosition().getZ());
			obj->draw();
		glPopMatrix();
	}

	_ground->draw();

	//FINISH DRAWING PHASE
	//FLUSH OPENGL CONTEXT
	glFlush();
	glutSwapBuffers();
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
	case int('1') :
		_currentCamera = _cameras[0];
		break;
	case int('2') :
		_currentCamera = _cameras[1];
		break;
	case int('3'):
		_currentCamera = _cameras[2];

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
	_currentCamera = _cameras[0];

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition(700,100);
	glutCreateWindow("");
	glEnable(GL_DEPTH_TEST);


	GameManager::setupCallbacks();
	glutReshapeFunc(GameManager::reshapeCallback);
	glutSpecialFunc(GameManager::specialCallback);
	glutSpecialUpFunc(GameManager::specialUpCallback);
	glutKeyboardFunc(GameManager::keypressCallback);
	glutDisplayFunc(GameManager::displayCallback);
	glutTimerFunc(15, GameManager::timerCallback, 0);

	glutMainLoop();

}

void GameManager::addGameObject(Car* _obj) {
	_cars.push_back(_obj);
}
void GameManager::addGameObject(RoadSide* _obj) {
	_track.push_back(_obj);
}
void GameManager::addGameObject(Butter* _obj) {
	_butters.push_back(_obj);
}
void GameManager::addGameObject(Orange* _obj) {
	_oranges.push_back(_obj);
}
void GameManager::addGameObject(Track* _obj) {
	_ground = _obj;
}
void GameManager::addCamera(Camera* _obj) {
	_cameras.push_back(_obj);
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

void GameManager::setDebugMode(bool _val) {
	debug_mode = _val;
}
