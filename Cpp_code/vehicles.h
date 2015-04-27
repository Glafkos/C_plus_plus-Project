#pragma once
# define VEHICLES_H

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define UP_LEFT 4
# define UP_RIGHT 5
# define DOWN_LEFT 6
# define DOWN_RIGHT 7

# include <iostream>
# include "position.h"
# include "PlanetSpot.h"
# include <time.h>

using std::cout;
using std::cin;
using std::endl;

class Vehicles
{
public:
	Vehicles(bool sit=true, float abil=0.5, int sp=50, int a=0, int b=0);
	virtual ~Vehicles(void);

	/* sinartisi metakinisis kata mia thesi */
	position move(int go, PlanetSpot *map[side][side]);

	/* pithanotita vlavis */
	float damage_possibility(PlanetSpot *plSp); /* epistrefomeni timi [0, 1] */

	/* orizw tixaies times gia tin ikanotita prosvasis */
	void setRandomAbility();

	/* tiponei tis plirofories tou oximatos */
	virtual void printInfo();

	/* tiponei tin trexousa thesi */
	void printCurrentPosition();

	/* sinartiseis oi opoies thetoun tin thesi i,j tou oximatos */
	void setPositionI(int a, PlanetSpot *map[side][side]);
	void setPositionJ(int b, PlanetSpot *map[side][side]);
	void setPosition( position pos, PlanetSpot *map[side][side] );
	void setPosition( int a, int b, PlanetSpot *map[side][side]);

	/* sinartiseis oi opoies epistrefoun tin thesi i,j tou oximatos */
	position getPosition();
	int getPositionI();
	int getPositionJ();

	/* auksanei tis vlaves opou exei pathei to sigkekrimeno oxima kai tis vlaves olwn twn oximatwn */
	void plusDamage();

	/* apofasizei gia to an telika tha pathei vlavi to oxima i oxi */
	void sufferDamage(PlanetSpot *pls);

	virtual	void operation(PlanetSpot *map[side][side]);

	void setSituation(bool situa);

	bool getSituation();

	void setRoundsWithDamage(int i);
	int getRoundsWithDamage();

	static int getAllVehiclesDamageCounter();

protected:
	int speed;
	bool situation; /* katastasi oximatos -> doulevei\den doulevei */
	float ability; /* ikanotita prosvasis pedio orismou [0.1, 1] */
	int move_counter; /* metraei to poses fores exei metakinithei to oxima */
	int damage_counter; /* metraei to poses vlaves exei ipostei to oxima */
	static int all_vehicles_damage_counter;
	position current_position; 	/* einai i trexousa thesi tou oximatos */
	int roundsWithDamage;
	

};

