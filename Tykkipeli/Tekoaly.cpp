#include "Tekoaly.h"



Tekoaly::Tekoaly(int taso)
{
	this->taso=taso;
	this->x=700;
	this->y=550;
	this->ammuskoko=10;
}


void Tekoaly::Pelaa(World *world)
{

	world->luoAmmus(new Ammus(ammuskoko,-90.0,80.0,x,y));
	//world.
}




Tekoaly::Tekoaly(void)
{
}


Tekoaly::~Tekoaly(void)
{
}
