#include "Ammus.h"
#include "stdafx.h"
using namespace std;

Ammus::Ammus(double voima_x,double voima_y,int x,int y)
{
	
	this->voima_g=-98,1;
	this->voima_x=voima_x;
	this->voima_y=voima_y;
	this->pos_x=x;
	this->ppos_x=x;
	this->pos_y=y;
	this->ppos_y=y;

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
void Ammus::stop()
{
	voima_g=0;
	voima_x=0;
	voima_y=0;
}


