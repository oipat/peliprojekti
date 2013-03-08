#pragma once
#include <vector>
#include "Ammus.h"


class World
{
public:
	World(void);
	~World(void);

	std::vector<Ammus*> getAmmukset();
	void destroyAmmus(Ammus*);
	void luoAmmus(Ammus*);
private:
	std::vector<Ammus*> ammukset;
};

