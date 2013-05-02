#pragma once
#include "Maasto.h"

class Ammus
{
			
private:
	double koko;
    double voima_x;
    double voima_y;
    double voima_g;
    int pos_x, pos_y, ppos_x, ppos_y;
	
public:
	Ammus(double koko,double voima_x,double voima_y,int x,int y);
	Ammus();
	~Ammus(void);
	void setKoko(double k) { koko=k;}
	double getKoko() const {return koko;}
	void setVoima_x(double v) {voima_x=v;}
	void setVoima_y(double v) {voima_y=v;}
	void setVoima_g(double v) {voima_g=v;}
	double getVoima_x() const {return voima_x;}
	double getVoima_y() const {return voima_y;}
	double getVoima_g() const {return voima_g;}
	int getPos_x() const {return pos_x;}
	int getPos_y() const {return pos_y;}
	int getPPos_x() const {return ppos_x;}
	int getPPos_y() const {return ppos_y;}
	void nextX(int time);
	void nextY(int time);
	void stop();
	bool collides(Ammus *other);
	bool maastoCollision(Maasto *maasto);
	double determinant(Piste vec1, Piste vec2);
	bool edgeIntersection(Piste a, Piste b, Piste c, Piste d);
	
	
	
};