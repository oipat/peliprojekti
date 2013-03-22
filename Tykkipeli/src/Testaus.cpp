#include "Testaus.h"

using namespace std;


int main(int argc, char* argv[])
{

	Piirto piirto = Piirto();
	piirto.alustaPiirto(800, 600, 32);

	World world = World();
	
	Ammus *ammus1 = new Ammus(1,11,111,1111);
	Ammus *ammus2 = new Ammus(2,22,222,2222);
	Ammus *ammus3 = new Ammus(3,33,333,3333);
	Ammus *ammus4 = new Ammus(4,44,444,4444);

	world.luoAmmus(ammus1);
	world.luoAmmus(ammus2);
	world.luoAmmus(ammus3);
	world.luoAmmus(ammus4);

	world.tulostaAmmukset();
	world.destroyAmmus(ammus2);
	cout << endl << "ammus 2 tuhottu" << endl << endl;
	world.tulostaAmmukset();

	/*cout << "voima x: " <<ammus->getVoima_x() <<endl;
	cout << "voima y: " <<ammus->getVoima_y() <<endl;
	time_t msec = time(0) * 1000;
	cout << "pos x: " <<ammus->getPos_x() <<endl;
	msec = msec - time(0) * 1000;
	ammus->nextX(msec+100);
	cout << "pos x 2: " <<ammus->getPos_x() <<endl;
	cout << "ppos x: " <<ammus->getPPos_x() <<endl;

	cout << "pos y: " <<ammus->getPos_y() <<endl;
	
	ammus->nextY(10);
	cout << "pos y 2: " <<ammus->getPos_y() <<endl;*/
	cin.get();

	return 0;
}

