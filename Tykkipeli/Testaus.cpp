#include "stdafx.h"
#include "Ammus.h"
#include "Testaus.h"
#include "SDL.h"
using namespace std;


int main(int argc, char* argv[])
{
	int oldTime, newTime, deltaTime;
	bool quit = false;
	
	World world = World();
	world.luoAmmus(new Ammus(10,52.0,42.0,120,222));
	world.luoAmmus(new Ammus(10,52.0,42.0,111,217));

	Gui gui = Gui(&world);
	gui.init(1024, 768, 32);


	oldTime = SDL_GetTicks();
	while(!quit) {
		newTime = SDL_GetTicks();
		deltaTime = newTime - oldTime;
		oldTime = newTime;

		gui.drawFrame(deltaTime);
	}

	cin.get();

	return 0;
}

