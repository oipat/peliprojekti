#include "Tekoaly.h"



Tekoaly::Tekoaly(int taso)
{
	this->taso=taso;
	this->x=705;
	this->y=550;
	this->ammuskoko=10;
	if(taso==1)
	{
	this->power=-55;
	}
	else if(taso==2)
	{
		this->power=-38;
	}
	else if(taso==3)
	{
		this->power=-26;
	}
	
	
	this->ammuttu=0;
}


void Tekoaly::Pelaa(World *world)
{
	world->luoAmmus(new Ammus(ammuskoko,power,115.0,x,y));
	

	if(ammuttu<8){

	ammuttu++;
	}
	if(taso==1)
	{
	if(power>=-20)
	{
	this->power=power-(rand()%(25-ammuttu)+1);
	}
	else
	{
	this->power=power+(rand()%(25-ammuttu)+1);
	}
	}
	else if(taso==2)
	{
		if(power>=-25)
	{
		this->power=power-1;
	}
	else
	{
	this->power=power+(rand()%(10-ammuttu)+1);
	}
	}
	


}



Tekoaly::Tekoaly(void)
{
}


Tekoaly::~Tekoaly(void)
{
}
