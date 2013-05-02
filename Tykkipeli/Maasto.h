#pragma once
#include <vector>
#include "Piste.h"
class Maasto
{
public:
	Maasto(void);
	Maasto(std::vector<Piste*> uudetPisteet);
	~Maasto(void);
	void lisaaPiste(Piste* p);
	std::vector<Piste*> pisteet;
private:

};

