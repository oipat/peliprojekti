#include "Mainloop.h"
#include "windows.h"
using namespace std;

int main(int argc, char* argv[])
{
	int deltaTime=0,aiTime=0,oTime,nTime,dTime;
	bool quit = false;


	// Maaston polygonin pisteet
	Maasto maasto = Maasto();
	maasto.lisaaPiste(new Piste(100, 610));
	maasto.lisaaPiste(new Piste(330, 600));
	maasto.lisaaPiste(new Piste(500, 313));
	maasto.lisaaPiste(new Piste(530, 283));
	maasto.lisaaPiste(new Piste(700, 600));
	maasto.lisaaPiste(new Piste(900, 610));
	maasto.lisaaPiste(new Piste(900, 768));
	maasto.lisaaPiste(new Piste(100, 768));


	World world = World(1024, 768, &maasto);
	Tykki* tykki=new Tykki(100,1,300,600,30,30,true);
	world.luoTykki(tykki);
	Tykki* tykki2=new Tykki(100,1,700,600,30,30,false);
	world.luoTykki(tykki2);
	Gui gui = Gui(&world);
	gui.init(world.getKokoX(), world.getKokoY(), 32);

	InputHandler inputHandler = InputHandler();
	Tekoaly ai= Tekoaly(1);
	
	
		
	oTime=SDL_GetTicks();
	while(!quit) {
		

		// inputhandlaus
		inputHandler.handleInput();
		if(inputHandler.isQuit()) {
			quit = true;
		}
		
		// testausta vain "jee hiiri liikkuu"
		gui.drawAmmus(&Ammus(10, 10, 10, inputHandler.getMouseX(), inputHandler.getMouseY()));

		gui.drawFrame();		
		if(aiTime>1500)
		{
			ai.Pelaa(&world);
			aiTime=0;
		}
		if(inputHandler.isMouseClicked()&&deltaTime>(int)(tykki->getReloadAika()*1000))
		{
			world.luoAmmus(new Ammus(10,(inputHandler.getMouseX()-tykki->getPosX())/2,(tykki->getPosY()-inputHandler.getMouseY())/2,tykki->getPosX()+10,tykki->getPosY()-50));
			deltaTime=0;
		}
		
		
		
		nTime = SDL_GetTicks();
		dTime = nTime - oTime;
		oTime = nTime;
		deltaTime+=dTime;
		aiTime+=dTime;

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
					/*delete(tykki);
					delete(tykki2);
					delete(&inputHandler);
					delete(&ai);
					delete(&gui);
					delete(&world);*/
					main(1,NULL);
				}
				else
				{
					quit=true;
					break;
				}
				break;
			}
		
		
	}
	
	SDL_Quit();
	
	return 0;
}



