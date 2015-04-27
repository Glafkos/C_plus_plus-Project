#pragma once
#define RESCUER_H
#include <iostream>
#include "Vehicles.h"

using namespace std;

class Rescuer : public Vehicles
{
	protected:
		int fixCounter; //metraei to posa oximata exei epidiorthosei
	public:
		Rescuer(bool sit=true, float abil=0.5, int sp=50, int a=0, int b=0);
		~Rescuer();

		void printInfo();
		void operation(PlanetSpot *map[side][side]);


};


