#include "World.h"

#include <iostream>


World::World(int kokoX, int kokoY, Maasto* maasto)
{
	// alustetaan vektorik, sisältää Ammus-olioiden pointereita
	this->ammukset = std::vector<Ammus*>();
	this->tykit = std::vector<Tykki*>();
	this->kokoX = kokoX;
	this->kokoY = kokoY;
	this->loppu=false;
	this->pelaajavoitti=false;
	this->maasto = maasto;
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

Maasto* World::getMaasto() {
	return this->maasto;
}

void World::luoAmmus(Ammus *uusiAmmus) {
	this->ammukset.push_back(uusiAmmus);
}

void World::luoTykki(Tykki *uusiTykki) {
	this->tykit.push_back(uusiTykki);
}

void World::destroyAmmus(Ammus *tuhottavaAmmus) {
			
	std::vector<Ammus*>::iterator iter;
	tuhottavaAmmus->stop();
	// testattu
	// iteroi ammuslista
	if(ammukset.size()>0){
	for(iter = ammukset.begin(); iter != ammukset.end(); iter++) {
		// jos tuhottavan ammuksen muistiosoite täsmää vektorissa olevaan
		if(tuhottavaAmmus == *iter) {
			// tuhotaan vektorista
			iter = ammukset.erase(iter);
			// tuhotaan myös itse olio
			delete tuhottavaAmmus;
			break;
		}
	}}
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
	if(ammukset.size()>0){

	for each (Ammus *ammus in ammukset)
	{
		ammus->nextX(time);
		ammus->nextY(time);

		if(ammus->getPos_x() > this->kokoX || ammus->getPos_x() < 0) {
			destroyAmmus(ammus);
			goto escape;
		}
		if(ammus->getPos_y() > this->kokoY) {
			destroyAmmus(ammus);
			goto escape;
		}

		if(ammus->maastoCollision(this->maasto)) {
			destroyAmmus(ammus);
			goto escape;
		}
		for each (Ammus *other in ammukset)
		{
			if(ammus->collides(other))
			{
				destroyAmmus(ammus);
				destroyAmmus(other);
				goto escape;
				//break;
			}
		}
		for each (Tykki *tykki in tykit)
		{
			if(tykki->collides(ammus))
			{
				loppu=true;
				if(!tykki->getHuman())
				{
					pelaajavoitti=true;
				}
				//destroyTykki(tykki);
				//destroyAmmus(ammus);
				goto escape;
				//break;
			}
		}
	}
	}
escape:
	std::cout <<"escape the loop";
}


void World::tulostaAmmukset() {
	std::vector<Ammus*>::iterator iter;
	
	for(iter = this->ammukset.begin(); iter != this->ammukset.end(); iter++) {
		std::cout << "x: " << ((Ammus*) *iter)->getPos_x();
		std::cout << "\ty: " << ((Ammus*) *iter)->getPos_y();
		std::cout << std::endl;
	}
}

bool World::getLoppu()
{
	return this->loppu;
}

bool World::getPelaajavoitti()
{
	return this->pelaajavoitti;
}