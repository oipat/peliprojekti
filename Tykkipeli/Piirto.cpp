#include "Piirto.h"


Piirto::Piirto(void)
{
}


Piirto::~Piirto(void)
{
}

void Piirto::alustaPiirto(int x, int y, int cDepth) {
	SDL_Surface* screen = NULL;
	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	//Set up screen
	screen = SDL_SetVideoMode( x, y, cDepth, SDL_SWSURFACE );

}