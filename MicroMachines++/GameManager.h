#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Collection.h"
#include "Camera.h"
#include "GameObject.h"
#include "PerspectiveCamera.h"
#include "OrthogonalCamera.h"
#include "Butter.h"
#include "Car.h"
#include "Orange.h"
#include "RoadSide.h"
#include "Track.h"
#include <time.h>
#include "Printer.h"

class GameManager {
private:
	std::vector<Camera*> _cameras;

	std::vector<Butter*> _butters;
	std::vector<Orange*> _oranges;
	std::vector<RoadSide*> _track;
	//_cars[0] -> player controlled car; vector 
	std::vector<Car*> _cars;
	Track* _ground;

	Printer _printer;

	Camera *_currentCamera;
	// std::vector<LightSource> _light_Sources; //

	// implementação baseada no necessário para a primeira entrega //

	bool debug_mode = false;
	double rotate_y = 0;
	double rotate_x = 0;
	float _scaling_factor = 1.0f;

public:

	GameManager();
	~GameManager();

	void addGameObject(Car* _obj);
	void addGameObject(RoadSide* _obj);
	void addGameObject(Butter* _obj);
	void addGameObject(Orange* _obj);
	void addGameObject(Track* _obj);
	void addCamera(Camera* _obj);

	Car* getCar(int i);
	/*RoadSide getGameObject(int i);
	Butter getGameObject(int i);
	Orange getGameObject(int i);
	Track getGameObject();
	*/

	void init(int argc, char** argv);

	void setDebugMode(bool v);

	void keyPressed(unsigned char key, int x, int y);

	void onTimer();

	void idle();

	void update();

	void myReshape(GLsizei w, GLsizei h);

	void setupCallbacks();

	static void keypressCallback(unsigned char key, int x, int y);

	static void specialCallback(int key, int x, int y);

	static void reshapeCallback(int x, int y);
	
	static void specialUpCallback(int key, int x, int y);

	static void timerCallback(int i);
	
	static void displayCallback();

	void calcFPS();

	void display();

	void specialKeys(int key, int x, int y);

	void specialUpKeys(int key, int x, int y);


};

#endif