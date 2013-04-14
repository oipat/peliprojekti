#include "stdafx.h"
#include "Ammus.h"
#include "Testaus.h"
#include "SDL.h"
using namespace std;


int main(int argc, char* argv[])
{
	int oldTime, newTime, deltaTime;
	bool quit = false;
	SDL_Event event;
	
	World world = World();
	Ammus* ammus1 = new Ammus(10,52.0,42.0,120,222);
	world.luoAmmus(ammus1);
	world.luoAmmus(new Ammus(10,52.0,42.0,111,217));

	Gui gui = Gui(&world);
	gui.init(1024, 768, 32);


	oldTime = SDL_GetTicks();

	while(!quit) {
		newTime = SDL_GetTicks();
		deltaTime = newTime - oldTime;
		oldTime = newTime;

		// inputhandlaus, vois ehkä laittaa toisee luokkaa
		if(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			if (event.type == SDL_KEYDOWN)
			{
				SDLKey keyPressed = event.key.keysym.sym;
				switch (keyPressed)
				{
					case SDLK_ESCAPE:
					quit = true;
					break;
				}
			}
		}

		// testausta vain "jee hiiri liikkuu"
		int x,y;
		SDL_GetMouseState(&x, &y);
		gui.drawAmmus(&Ammus(10, 10, 10, x, y));

		gui.drawFrame();
	}

	SDL_Quit();
	
	return 0;
}


