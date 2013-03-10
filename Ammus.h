#pragma once

class Ammus
{
			
private:
	//double paino;
    double voima_x;
    double voima_y;
    double voima_g;
    int pos_x, pos_y, ppos_x, ppos_y;
	
public:
	Ammus(double voima_x,double voima_y,int x,int y);
	Ammus();
	~Ammus(void);
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
	void nextX(long time);
	void nextY(long time);
	void stop();
	
	
	
	
};