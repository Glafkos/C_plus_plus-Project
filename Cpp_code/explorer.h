#pragma once
# define EXPLORER_H

# include "Vehicles.h"
# include "PlanetSpot.h"

using namespace std;


class  Explorer : public Vehicles 
{
public:
	Explorer(bool sit=true, float abil=0.5, int sp=50, int a=0, int b=0);
	~Explorer();

	/* tiponei plirofories gia ton explorer */
	void printInfo();

	/* PROSORINI DILWSEI! THA GINEI ME POLIMORFISMO */
	void operation(PlanetSpot *map[side][side]);

	void plusFlagCounter();

	static int getAllFlagCounter();

private:
	int flagCounter;  /* posotita simewn pou kataxwrise */
	static int all_flag_counter;
};



