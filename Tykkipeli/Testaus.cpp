#include "stdafx.h"
#include "Ammus.h"
#include "Testaus.h"
#include "SDL.h"
using namespace std;


int main(int argc, char* argv[])
{
	bool quit = false;
	Gui gui = Gui();
	gui.init(1024, 768, 32);

	int oldTime, newTime, deltaTime;
	oldTime = SDL_GetTicks();

	while(!quit) {
		newTime = SDL_GetTicks();
		deltaTime = newTime - oldTime;
		oldTime = newTime;

		gui.drawFrame(deltaTime);
	}


	 Ammus *ammus= new Ammus(10,52.0,42.0,120,222);
	 Ammus *ammus2= new Ammus(10,52.0,42.0,111,217);
	 if(ammus->collides(ammus2))
	 {
		 cout<<"TORMAYS JUMANKEKKANA\n";
	 }

	cin.get();

	return 0;
}

