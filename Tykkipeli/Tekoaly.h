#pragma once
#include "Ammus.h"
#include "World.h"
class Tekoaly
{

private:
	int taso,ammuskoko,voima_x,voima_y,x,y;

public:
	void Pelaa(World* world);
	Tekoaly(int taso);
	Tekoaly(void);
	virtual ~Tekoaly(void);
};

