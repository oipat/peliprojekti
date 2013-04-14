#include "Gui.h"


Gui::Gui(World *world)
{
	this->world = world;
}


Gui::~Gui(void)
{
}

void Gui::init(int x, int y, int colors) {
	this->x = x;
	this->y = y;

	SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_ShowCursor(0);
	this->screen = SDL_SetVideoMode(x, y, colors, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Tykkipeli 0.1", 0 );
}


void Gui::drawTykki(Tykki *tykki) {
}

void Gui::drawAmmus(Ammus *ammus) {
			filledEllipseRGBA(this->screen,
                ammus->getPos_x(), ammus->getPos_y(),
               (Sint16) ammus->getKoko()/2, (Sint16) ammus->getKoko()/2,
                255, 0, 0, 255);
}

void Gui::drawMaasto() {

}

void Gui::drawFrame() {
	drawMaasto();

	for each (Ammus *ammus in this->world->getAmmukset())
	{
		drawAmmus(ammus);
	}

	SDL_Flip(this->screen);
	SDL_FillRect(this->screen, NULL, 0x000000);
}
