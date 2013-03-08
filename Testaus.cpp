#include "stdafx.h"
#include "Ammus.h"
using namespace std;

int main(void)
{

	Ammus *ammus= new Ammus(52.0,12.0,12,535);
	cout << "trololol" <<ammus->getVoima_x() <<endl;
	cout << "voima y" <<ammus->getVoima_y() <<endl;
	
	cin.get();
	return 0;
}

