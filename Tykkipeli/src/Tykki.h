#pragma once
#include "Ammus.h"

class Tykki
{
private:
	double health;
	double reloadAika;
	int pos_x, pos_y,korkeus,leveys;



public:
	Tykki();
	~Tykki(void);
	Tykki(double h,double r,int x,int y,int k,int l);
	bool collides(Ammus *a);

};