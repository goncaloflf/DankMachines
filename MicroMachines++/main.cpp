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
	float x, z;
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
		cout << x << "  " << z << "  " <<_orange->getPosition().getX() << "  " << _orange->getPosition().getZ()<< endl;
		_manager->addGameObject(_orange);
	}
	_manager->addGameObject(new RoadSide(0, 0, 0));
	_manager->addGameObject(new Track());
	_manager->init(argc,argv);

	
	
	return 0;
}