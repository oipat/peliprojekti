#pragma once
#include "Ammus.h"
#include "World.h"
class Tekoaly
{

private:
	int taso,ammuskoko,x,y,ammuttu;

	double power,voima_x,voima_y;
public:
	void Pelaa(World* world);
	Tekoaly(int taso);
	Tekoaly(void);
	virtual ~Tekoaly(void);
};

