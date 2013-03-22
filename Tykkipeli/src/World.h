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
	void World::tulostaAmmukset();
private:
	std::vector<Ammus*> ammukset;
};

