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

void Ammus::nextX(int time)
{
	int apumuuttuja=this->pos_x;
	this->pos_x=(int)(ppos_x+(voima_x*time/100));
	this->ppos_x=apumuuttuja;
}

void Ammus::nextY(int time)
{
	int apumuuttuja=this->pos_y;
	voima_y=voima_y+(voima_g*time/1000);
	this->pos_y=(int)(ppos_y+(voima_y*time/100*-1));
	this->ppos_y=apumuuttuja;
}

bool Ammus::collides(Ammus *other)
{
	//cout<<"Thissin tiedot:"<<this->pos_x<<": "<<this->pos_y<<"\n";
	//cout<<"other tiedot: "<<other->pos_x<<": "<<other->pos_y<<"\n";
if(this != other)
{
	return !((this->pos_x+this->koko<=other->pos_x)||(this->pos_x>=other->pos_x+other->koko)||(this->pos_y+this->koko<=other->pos_y)||(this->pos_y>=other->pos_y+this->koko));	
}
else
{
return false;
}

}


bool Ammus::maastoCollision(Maasto *maasto) {
	Piste* prevPiste = NULL;
	double sade = this->koko/2;
	for each (Piste* piste in maasto->pisteet)
	{
		if(prevPiste == NULL) {
			prevPiste = piste;
			continue;
		}

		// reuna vasemmasta alanurkasta ylös
		if(edgeIntersection(*prevPiste, *piste, Piste(this->pos_x-sade, this->pos_y+sade), Piste(this->pos_x-sade, this->pos_y-sade))) {
			return true;
		}
		// reuna vasemmasta ylänurkasta oikealle
		else if(edgeIntersection(*prevPiste, *piste, Piste(this->pos_x-sade, this->pos_y-sade), Piste(this->pos_x+sade, this->pos_y-sade))) {
			return true;
		}
		// reuna oikeasta ylänurkasta alas
		else if(edgeIntersection(*prevPiste, *piste, Piste(this->pos_x+sade, this->pos_y-sade), Piste(this->pos_x+sade, this->pos_y+sade))) {
			return true;
		}
		// reuna oikeasta alanurkasta vasemmalle
		else if(edgeIntersection(*prevPiste, *piste, Piste(this->pos_x+sade, this->pos_y+sade), Piste(this->pos_x-sade, this->pos_y+sade))) {
			return true;
		}
		prevPiste = piste;
	}
	return false;
}

// <copypaste> lähde: http://content.gpwiki.org/index.php/Polygon_Collision

double Ammus::determinant(Piste vec1, Piste vec2){
     return vec1.x * vec2.y - vec1.y * vec2.x;
 }
 
 //one edge is a-b, the other is c-d
 bool Ammus::edgeIntersection(Piste a, Piste b, Piste c, Piste d){
     double det = determinant(b - a, c - d);
     double t   = determinant(c - a, c - d) / det;
     double u   = determinant(b - a, c - a) / det;
     if ((t < 0) || (u < 0) || (t > 1) || (u > 1)) {
         return false;
     } else {
         return true;
     }
 }

 // </copypaste>

void Ammus::stop()
{
	voima_g=0;
	voima_x=0;
	voima_y=0;
}


