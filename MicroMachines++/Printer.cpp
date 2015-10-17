#include "Printer.h"



Printer::Printer()
{
}


Printer::~Printer()
{
}

void Printer::printPosition(GameObject *_obj) {
	if(printerOn)
	cout << "X: " << _obj->getPosition().getX() << " Y: " << _obj->getPosition().getY() << " Z: " << _obj->getPosition().getZ() << endl;
}
