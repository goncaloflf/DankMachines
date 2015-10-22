#include "Collection.h"
#include "GameManager.h"

//TODO
/*
Funcao add game object
adiciona ao vector de objectos
inicializa em globalscope
sem chamar construtores
passar um pointer para funçao
*/

GameManager *_manager;

int main(int argc, char* argv[]) {
	int i;
	float x, z, angle;
	_manager = new GameManager();
	srand(static_cast <unsigned> (time(0)));

	_manager->addGameObject(new Car(0, 0, 0));
	
	//added flexibility for starting game objects
	for (i = 0; i < 3; i++) {
		x = _orthoWidth + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (_orthoHeight - _orthoWidth)));
		z = _orthoWidth + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (_orthoHeight - _orthoWidth)));
		Butter *_butter;
		_butter = new Butter(x,0,z);
		_manager->addGameObject(_butter);
	}
	for (i = 0; i < 5; i++) {
		x = _orthoWidth + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (_orthoHeight - _orthoWidth)));
		z = _orthoWidth + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (_orthoHeight - _orthoWidth)));
		Orange *_orange;
		_orange = new Orange(x,0,z);
		_manager->addGameObject(_orange);
	}
	angle = 0;
	for (i = 0; i < 30; i++) {
		
		RoadSide *_shitteos;
		_shitteos = new RoadSide(cos((angle*3.14)/180), 0, sin((angle*3.14) / 180));
		_manager->addGameObject(_shitteos);
		angle += 12;
	}
	angle = 0;
	for (i = 0; i < 60; i++) {

		RoadSide *_shitteos;
		_shitteos = new RoadSide(1.6*cos((angle*3.14) / 180), 0, 1.6*sin((angle*3.14) / 180));
		_manager->addGameObject(_shitteos);
		angle += 6;
	}
	//ground
	_manager->addGameObject(new Track());

	_manager->addCamera(new OrthogonalCamera(Vector3(0,1,0), Vector3(0,0,1), Vector3(0,0,0), -2.f, 2.f, -2.f, 2.f, -2.f, 2.f));
	_manager->addCamera(new PerspectiveCamera(Vector3(0, 5, 0), Vector3(0, 0, 1), Vector3(0, 0, 0), 0.1f, 100.f, 45, 1));
	_manager->addCamera(new PerspectiveCamera());

	_manager->init(argc,argv);
	return 0;
}