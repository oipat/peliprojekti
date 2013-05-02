#pragma once
#include "Ammus.h"

class Tykki
{
private:
	double health;
	double reloadAika;
	int pos_x, pos_y,korkeus,leveys;
	bool human;



public:
	Tykki();
	~Tykki(void);
	Tykki(double h,double r,int x,int y,int k,int l,bool human);
	bool collides(Ammus *a);
	int getPosX();
	int getPosY();
	int getKorkeus();
	int getLeveys();
	double getReloadAika();
	bool getHuman();
};