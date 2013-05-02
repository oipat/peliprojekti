#include "Piste.h"


Piste::Piste(double x, double y)
{
	this->x = x;
	this->y = y;
}


Piste::~Piste(void)
{
}

Piste& Piste::operator -=(const Piste& v)
        {
            x -= v.x;
            y -= v.y;
            return (*this);
        }

 Piste Piste::operator -(const Piste& v)
{
	return (Piste(x - v.x, y - v.y));
}
