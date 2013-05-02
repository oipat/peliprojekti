#include "SDL.h"
#include "SDL_gfxPrimitives.h"
#include "Tykki.h"
#include "Ammus.h"
#include "World.h"
#include "Maasto.h"

#pragma once

class Gui
{
public:
	Gui(World *world);
	~Gui(void);
	void init(int x, int y, int colors);
	void drawTykki(Tykki *tykki);
	void drawAmmus(Ammus *ammus);
	void drawMaasto(Maasto *maasto);
	void drawFrame();
private:
	int x, y;
	SDL_Surface* screen;
	World *world;
};

