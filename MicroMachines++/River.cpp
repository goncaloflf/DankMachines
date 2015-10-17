#include "River.h"

	River::River(double x, double y, double z) {
		StaticObject::StaticObject(x, y, z);
	}

	River::~River() { 
		StaticObject::~StaticObject(); 
	}

	void River::draw() {}

