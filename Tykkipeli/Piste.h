#pragma once
class Piste
{
public:
	Piste(double, double);
	~Piste(void);
	double x, y;
	Piste& operator -=(const Piste& v);
	Piste operator -(const Piste& v);
        
};

