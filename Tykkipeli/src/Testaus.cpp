#include "stdafx.h"
#include "Ammus.h"
using namespace std;

int main(void)
{

	Ammus *ammus= new Ammus(52.0,42.0,12,535);
	cout << "voima x: " <<ammus->getVoima_x() <<endl;
	cout << "voima y: " <<ammus->getVoima_y() <<endl;
	time_t msec = time(0) * 1000;
	cout << "pos x: " <<ammus->getPos_x() <<endl;
	msec = msec - time(0) * 1000;
	ammus->nextX(msec+100);
	cout << "pos x 2: " <<ammus->getPos_x() <<endl;
	cout << "ppos x: " <<ammus->getPPos_x() <<endl;

	cout << "pos y: " <<ammus->getPos_y() <<endl;
	
	ammus->nextY(10);
	cout << "pos y 2: " <<ammus->getPos_y() <<endl;
	cin.get();
	return 0;
}
