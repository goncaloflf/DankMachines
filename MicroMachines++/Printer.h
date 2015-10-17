#pragma once
#ifndef PRINTER_H
#define PRINTER_H
#include "Collection.h"
#include "GameObject.h"

class Printer
{
public:
	Printer();
	~Printer();

	void printPosition(GameObject *_obj);
};

#endif

