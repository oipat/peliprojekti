#pragma once
#include <vector>
#include "Ammus.h"
#include "Tykki.h"


class World
{
public:
	World(int kokoY, int kokoX);
	~World(void);

	std::vector<Ammus*> getAmmukset();
	std::vector<Tykki*> getTykit();
	void destroyAmmus(Ammus*);
	void destroyTykki(Tykki*);
	void luoAmmus(Ammus*);
	void luoTykki(Tykki*);
	void update(int time);
	void World::tulostaAmmukset();
	int getKokoX();
	int getKokoY();
private:
	std::vector<Ammus*> ammukset;
	std::vector<Tykki*> tykit;
	// pikseleitä?
	int kokoX;
	int kokoY;
};

