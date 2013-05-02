#include "Mainloop.h"
#include "windows.h"
using namespace std;

int main(int argc, char* argv[])
{
	int oldTime, newTime, deltaTime,oTime,nTime,dTime;
	bool quit = false;
	
	World world = World(1024, 768);
	Tykki* tykki=new Tykki(100,1,300,600,30,30,true);
	world.luoTykki(tykki);
	world.luoTykki(new Tykki(100,1,700,600,30,30,false));
	Gui gui = Gui(&world);
	gui.init(world.getKokoX(), world.getKokoY(), 32);

	InputHandler inputHandler = InputHandler();
	Tekoaly ai= Tekoaly(1);
	
	oldTime = SDL_GetTicks();
		
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
			ai.Pelaa(&world);
			world.luoAmmus(new Ammus(10,(inputHandler.getMouseX()-tykki->getPosX())/2,(tykki->getPosY()-inputHandler.getMouseY())/2,tykki->getPosX()+10,tykki->getPosY()-50));
		}
		
		
		
		nTime = SDL_GetTicks();
		dTime = nTime - oTime;
		oTime = nTime;


			world.update(dTime);
			SDL_Delay(10);
			
		
			if(world.getLoppu())
			{
				int valinta=0;
				if(world.getPelaajavoitti())
				{
				valinta=MessageBox(NULL, "Voitit! \nUudestaan?", "VICTORY", MB_YESNO | MB_ICONQUESTION);
				}
				else
				{
				valinta=MessageBox(NULL, "Hävisit! \nUudestaan?", "DEFEAT", MB_YESNO | MB_ICONQUESTION);
				}
				if(valinta==6)
				{
					main(1,NULL);
				}
				else
				{
					quit=true;
					break;
				}
			}
		
		
	}
	
	SDL_Quit();
	
	return 0;
}



