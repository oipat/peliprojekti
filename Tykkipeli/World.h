#pragma once
#include <vector>
#include "Ammus.h"
#include "Tykki.h"
#include "Maasto.h"


class World
{
public:
	World(int kokoY, int kokoX, Maasto* maasto);
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
	bool getLoppu();
	bool getPelaajavoitti();
	Maasto* getMaasto();

private:
	std::vector<Ammus*> ammukset;
	std::vector<Tykki*> tykit;
	Maasto* maasto;
	// pikseleitä?
	int kokoX;
	int kokoY;
	bool loppu;
	bool pelaajavoitti;
};

