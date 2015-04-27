#pragma once

#define ANALYST_H
#include <iostream>
#include "Vehicles.h"

using namespace std;


#define MIN_CONTENT 35; //elaxisti periextikotita gia na kani to oxima exorixi


class Analyst: public Vehicles

{
public:
	/**
	@brief constructor me overload.
	*/
	Analyst(bool sit=true, float abil=0.5, int sp=50, int a=0, int b=0, int cargo_pall=0, int cargo_irid=0, int cargo_lefk=0);
	

	~Analyst();

	void plusCargo();
	void printInfo();

	void operation(PlanetSpot *map[side][side]); //sinartisi leitourgias. kanei eksoriksi ta sistatika apo to simeio sto xarti

	int getCargo();
	void freeCargo();

protected:	

	int max_product;

	/**
	 @brief	fortio palladiou.
	 */

	int cargo_palladio;

	/**
	 @brief	fortio iridiou.
	 */

	int cargo_iridio;

	/**
	 @brief	fortio lefkoxrisou.
	 */

	int cargo_lefkoxrisos;
	static int all_cargo; //fortio gia ola ta analyst

};

