#include "SDL.h"
#include "SDL_gfxPrimitives.h"
#include "Tykki.h"

#pragma once
class Gui
{
public:
	Gui(void);
	~Gui(void);
	void init(int x, int y, int colors);
	void drawTykki(Tykki tykki);
	void drawFrame(int deltaTime);
private:
	int x, y;
	SDL_Surface* screen;
};

