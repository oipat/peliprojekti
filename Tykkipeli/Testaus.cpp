#include "stdafx.h"
#include "Ammus.h"
#include "Testaus.h"
using namespace std;

/*
int main(int argc, char* argv[])
{
	int oldTime, newTime, deltaTime,oTime,nTime,dTime;
	bool quit = false;
	
	World world = World(1024, 768);
	Ammus* ammus1 = new Ammus(10,52.0,42.0,120,222);
	world.luoAmmus(ammus1);
	world.luoAmmus(new Ammus(10,52.0,42.0,111,217));
	Tykki* tykki=new Tykki(100,1,300,600,30,30,true);
	world.luoTykki(tykki);
	world.luoTykki(new Tykki(100,1,700,600,30,30,false));
	Gui gui = Gui(&world);
	gui.init(world.getKokoX(), world.getKokoY(), 32);

	InputHandler inputHandler = InputHandler();

	oldTime = SDL_GetTicks();
	Ammus* ammus2=new Ammus(10,90.0,80.0,300,500);
	world.luoAmmus(ammus2);
	oTime=SDL_GetTicks();
	while(!quit) {
		newTime = SDL_GetTicks();
		deltaTime = newTime - oldTime;
		oldTime = newTime;

		// inputhandlaus
		inputHandler.handleInput();
		if(inputHandler.isQuit()) {
			quit = true;
		}
		
		// testausta vain "jee hiiri liikkuu"
		gui.drawAmmus(&Ammus(10, 10, 10, inputHandler.getMouseX(), inputHandler.getMouseY()));

		gui.drawFrame();		
		if(inputHandler.isMouseClicked())
		{
			world.luoAmmus(new Ammus(10,(inputHandler.getMouseX()-tykki->getPosX())/2,(tykki->getPosY()-inputHandler.getMouseY())/2,tykki->getPosX()+10,tykki->getPosY()-50));
		}
		
		
		
		nTime = SDL_GetTicks();
		dTime = nTime - oTime;
		oTime = nTime;


			world.update(dTime);
			SDL_Delay(10);
			//sleep(10);
		
		
		
		
	}

	SDL_Quit();
	
	return 0;
}

*/
