#include "World.h"


World::World(void)
{
	// alustetaan vektorik, sis�lt�� Ammus-olioiden pointereita
	this->ammukset = std::vector<Ammus*>();
}


World::~World(void)
{
}

std::vector<Ammus*> World::getAmmukset() {
	return this->ammukset;
}

void World::luoAmmus(Ammus *uusiAmmus) {
	this->ammukset.push_back(uusiAmmus);
}

void World::destroyAmmus(Ammus *tuhottavaAmmus) {
	std::vector<Ammus*>::iterator iter;
	
	// TODO: test
	// iteroi ammuslista
	for(iter = ammukset.begin(); iter != ammukset.end(); iter++) {
		// jos tuhottavan ammuksen muistiosoite t�sm�� vektorissa olevaan
		if(tuhottavaAmmus == *iter) {
			// tuhotaan vektorista
			iter = ammukset.erase(iter);
			// tuhotaan my�s itse olio
			delete tuhottavaAmmus;
		}
	}
}
