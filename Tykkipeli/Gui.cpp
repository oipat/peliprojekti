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
	SDL_WM_SetCaption("Tykkipeli 0.1.8", 0 );
}


void Gui::drawTykki(Tykki *tykki) {

	// tykki-polygonin x-koordinaatit Tykin koordinaatit määrittävät sen vasemman alakulman
	Sint16 argX[4] = {(Sint16) tykki->getPosX(),
		(Sint16)(tykki->getPosX()+tykki->getLeveys()/3),
		(Sint16)(tykki->getPosX()+(tykki->getLeveys()/3*2)),
		(Sint16) tykki->getPosX()+tykki->getLeveys()};

	// tykki-polygonin y-koordinaatit 
	Sint16 argY[4] = { (Sint16)tykki->getPosY(),
		(Sint16)tykki->getPosY() - tykki->getKorkeus(),
		(Sint16)tykki->getPosY() - tykki->getKorkeus(),
		(Sint16)tykki->getPosY()};

	filledPolygonRGBA(this->screen, argX, argY, 4,
                      0, 255, 0, 255);
}

void Gui::drawAmmus(Ammus *ammus) {
		filledEllipseRGBA(this->screen,
			(Sint16) ammus->getPos_x(), (Sint16) ammus->getPos_y(),
			// jaetaan kahdella koska ilmeisesti koko = halkaisija ja parametrit haluavat säteen
			(Sint16) ammus->getKoko()/2,
			(Sint16) ammus->getKoko()/2,
			255, 0, 0, 255);
}

void Gui::drawMaasto(Maasto *maasto) {
	int taulukko = maasto->pisteet.size();
	Sint16* argX = new Sint16[taulukko+1];
	Sint16* argY = new Sint16[taulukko+1];

	int i = 0;
	for each (Piste* p in maasto->pisteet)
	{
		argX[i] = p->x;
		argY[i] = p->y;
		i++;
	}

	// testimaasto
	/*Sint16 kuudesOsa = (Sint16)world->getKokoX()/6;
	Sint16 viidesOsa = (Sint16)world->getKokoY()/5;
	Sint16 kokoX = world->getKokoX();
	Sint16 kokoY = world->getKokoY();

	Sint16 argX[7] = {kuudesOsa*0, kuudesOsa*1, kuudesOsa*2, kuudesOsa*3, kuudesOsa*4, kuudesOsa*5, kuudesOsa*6};
	Sint16 argY[7] = {kokoY - viidesOsa*0, kokoY - viidesOsa*1, kokoY - viidesOsa*1, kokoY - viidesOsa*3, kokoY - viidesOsa*1, kokoY - viidesOsa*1, kokoY - viidesOsa*0};*/


	filledPolygonRGBA(this->screen,
                     argX, argY,
                      taulukko,
                      0, 0, 255, 255);
	delete [] argX;
	delete [] argY;
}

void Gui::drawFrame() {
	drawMaasto(world->getMaasto());

	for each (Ammus *ammus in this->world->getAmmukset())
	{
		drawAmmus(ammus);
	}
	
	for each (Tykki *tykki in this->world->getTykit())
	{
		drawTykki(tykki);
	}

	SDL_Flip(this->screen);
	SDL_FillRect(this->screen, NULL, 0x000000);
}
