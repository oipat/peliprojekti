#include "Ammus.h"
#include "stdafx.h"
using namespace std;

Ammus::Ammus(double koko,double voima_x,double voima_y,int x,int y)
{
	this->voima_g=-98,1;
	this->koko=koko;
	this->voima_x=voima_x;
	this->voima_y=voima_y;
	this->pos_x=x;
	this->ppos_x=x;
	this->pos_y=y;
	this->ppos_y=y;
}

Ammus::Ammus() {
}

Ammus::~Ammus(void) {
}

void Ammus::nextX(long time)
{
	this->pos_x=(int)(ppos_x+voima_x*time/1000);
}

void Ammus::nextY(long time)
{
	voima_y=voima_y+(voima_g*time/1000);
	cout <<"voima y: "<< voima_y <<endl;
	this->pos_y=(int)(ppos_y+(voima_y*time/1000*-1));
}

bool Ammus::collides(Ammus *other)
{
	cout<<"Thissin tiedot:"<<this->pos_x<<": "<<this->pos_y<<"\n";
	cout<<"other tiedot: "<<other->pos_x<<": "<<other->pos_y<<"\n";
if(this != other)
{
	return !((this->pos_x+this->koko<=other->pos_x)||(this->pos_x>=other->pos_x+other->koko)||(this->pos_y+this->koko<=other->pos_y)||(this->pos_y>=other->pos_y+this->koko));
	
}
else
{
return false;
}


}

void Ammus::stop()
{
	voima_g=0;
	voima_x=0;
	voima_y=0;
}


