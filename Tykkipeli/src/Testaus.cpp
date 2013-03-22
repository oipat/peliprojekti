#include "stdafx.h"
#include "Ammus.h"
#include "SDL.h"
using namespace std;


int main(int argc, char* argv[])
{
	
	 SDL_Surface* screen = NULL;
	 //Start SDL
	 SDL_Init(SDL_INIT_EVERYTHING);
	 //Set up screen
	 screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
	/* 
	Ammus *ammus= new Ammus(52.0,42.0,12,535);
	cout << "voima x: " <<ammus->getVoima_x() <<endl;
	cout << "voima y: " <<ammus->getVoima_y() <<endl;
	time_t msec = time(0) * 1000;
	cout << "pos x: " <<ammus->getPos_x() <<endl;
	msec = msec - time(0) * 1000;
	ammus->nextX(msec+100);
	cout << "pos x 2: " <<ammus->getPos_x() <<endl;
	cout << "ppos x: " <<ammus->getPPos_x() <<endl;

	cout << "pos y: " <<ammus->getPos_y() <<endl;
	
	ammus->nextY(10);
	cout << "pos y 2: " <<ammus->getPos_y() <<endl;
	*/
	 Ammus *ammus= new Ammus(10,52.0,42.0,120,222);
	 Ammus *ammus2= new Ammus(10,52.0,42.0,111,217);
	 if(ammus->collides(ammus2))
	 {
		 cout<<"TORMAYS JUMANKEKKANA\n";
	 }

	cin.get();

	return 0;
}

