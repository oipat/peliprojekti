#include "World.h"

#include <iostream>


World::World(int kokoX, int kokoY)
{
	// alustetaan vektorik, sisältää Ammus-olioiden pointereita
	this->ammukset = std::vector<Ammus*>();
	this->tykit = std::vector<Tykki*>();
	this->kokoX = kokoX;
	this->kokoY = kokoY;
}


World::~World(void)
{
}
int World::getKokoX() {
	return this->kokoX;
}
int World::getKokoY() {
	return this->kokoY;
}

std::vector<Ammus*> World::getAmmukset() {
	return this->ammukset;
}

std::vector<Tykki*> World::getTykit() {
	return this->tykit;
}

void World::luoAmmus(Ammus *uusiAmmus) {
	this->ammukset.push_back(uusiAmmus);
}

void World::luoTykki(Tykki *uusiTykki) {
	this->tykit.push_back(uusiTykki);
}

void World::destroyAmmus(Ammus *tuhottavaAmmus) {
			
	std::vector<Ammus*>::iterator iter;
	
	// testattu
	// iteroi ammuslista
	for(iter = ammukset.begin(); iter != ammukset.end(); iter++) {
		// jos tuhottavan ammuksen muistiosoite täsmää vektorissa olevaan
		if(tuhottavaAmmus == *iter) {
			// tuhotaan vektorista
			iter = ammukset.erase(iter);
			// tuhotaan myös itse olio
			delete tuhottavaAmmus;
			break;
		}
	}
}
void World::destroyTykki(Tykki *tuhottavaTykki) {
	
	for each (Tykki *tykki in tykit)
	{
			if(tuhottavaTykki == tykki) {
			// tuhotaan olio
			delete tuhottavaTykki;
			break;
		}
	}
			
}


void World::update(int time)
{
	for each (Ammus *ammus in ammukset)
	{
		ammus->nextX(time);
		ammus->nextY(time);
	for each (Ammus *other in ammukset)
	{
		if(ammus->collides(other))
		{
			destroyAmmus(ammus);
			destroyAmmus(other);
		}
	}
	for each (Tykki *tykki in tykit)
	{
		if(tykki->collides(ammus))
		{
			destroyTykki(tykki);
			destroyAmmus(ammus);
		}
	}
	}
	
}


void World::tulostaAmmukset() {
	std::vector<Ammus*>::iterator iter;
	
	for(iter = this->ammukset.begin(); iter != this->ammukset.end(); iter++) {
		std::cout << "x: " << ((Ammus*) *iter)->getPos_x();
		std::cout << "\ty: " << ((Ammus*) *iter)->getPos_y();
		std::cout << std::endl;
	}
}