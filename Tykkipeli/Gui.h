#include "SDL.h"
#include "SDL_gfxPrimitives.h"
#include "Tykki.h"
#include "Ammus.h"
#include "World.h"

#pragma once
class Gui
{
public:
	Gui(World *world);
	~Gui(void);
	void init(int x, int y, int colors);
	void drawTykki(Tykki *tykki);
	void drawAmmus(Ammus *ammus);
	void drawMaasto();
	void drawFrame(int deltaTime);
private:
	int x, y;
	SDL_Surface* screen;
	World *world;
};

