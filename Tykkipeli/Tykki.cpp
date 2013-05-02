#include "Tykki.h"
#include "stdafx.h"
using namespace std;


Tykki::Tykki(double health,double Aika,int x,int y,int korkeus,int leveys,bool human)
{
	this->health=health;
	this->reloadAika=Aika;
	this->pos_x=x;
	this->pos_y=y;
	this->leveys=leveys;
	this->korkeus=korkeus;
	this->human=human;
}

bool Tykki::collides(Ammus *ammus)
{
	return !((this->pos_x+this->leveys<=ammus->getPos_x())||(this->pos_x>=ammus->getPos_x()+ammus->getKoko())||(this->pos_y+this->korkeus<=ammus->getPos_y())||(this->pos_y>=ammus->getPos_y()+this->korkeus));

}

Tykki::Tykki()
{
}

Tykki::~Tykki(void)
{
}

int Tykki::getPosX() {
	return this->pos_x;
}
int Tykki::getPosY() {
	return this->pos_y;
}
int Tykki::getKorkeus() {
	return this->korkeus;
}
int Tykki::getLeveys() {
	return this->leveys;
}
bool Tykki::getHuman(){
	return this->human;
}