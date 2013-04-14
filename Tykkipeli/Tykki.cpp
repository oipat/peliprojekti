#include "Tykki.h"
#include "stdafx.h"
using namespace std;


Tykki::Tykki(double health,double Aika,int x,int y,int leveys,int korkeus)
{
	this->health=health;
	this->reloadAika=Aika;
	this->pos_x=x;
	this->pos_y=y;
	this->leveys=leveys;
	this->korkeus=korkeus;
}
/*
bool Tykki::collides(Ammus *ammus)
{
	return !((this->pos_x+this->leveys<=ammus->getPos_x)||(this->pos_x>=ammus->getPos_x+ammus->getKoko)||(this->pos_y+this->korkeus<=ammus->getPos_y)||(this->pos_y>=ammus->getPos_y+this->korkeus));

}
*/
Tykki::Tykki()
{
}

Tykki::~Tykki(void)
{
}