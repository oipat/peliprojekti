#include "Maasto.h"


Maasto::Maasto(std::vector<Piste*> uudetPisteet)
{
}

Maasto::Maasto(void)
{
	this->pisteet = std::vector<Piste*>();
}


Maasto::~Maasto(void)
{
}

void Maasto::lisaaPiste(Piste* p) {
	this->pisteet.push_back(p);
}
