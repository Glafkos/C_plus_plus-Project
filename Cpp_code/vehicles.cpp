#include "vehicles.h"


int Vehicles::all_vehicles_damage_counter = 0;

Vehicles::Vehicles(bool sit, float abil, int sp, int a, int b)
{
	move_counter = 0;
	damage_counter = 0;
	situation = sit;
	ability = abil;
	speed = sp;
	current_position.i = a;
	current_position.j = b;
	roundsWithDamage = 0;
//	cout << "Vehicles created with: " << endl;
//	printInfo();
}

Vehicles::~Vehicles()
{
	cout << "------------------------------------------------------------------ \n";
	cout << "Vehicles with: \n";
	printInfo();
	cout << "DELETED \n";  
	cout << "------------------------------------------------------------------ \n";
}

void Vehicles::setPositionI(int a, PlanetSpot *map[side][side])
{
//	cout << "Current Position before: " << current_position.i << ", " << current_position.j << endl;
	map[current_position.i][current_position.j]->setVehicle(nullptr);
	if (a < 0)
	{
		a = side + a;
	}
	current_position.i = a % side ;
	map[current_position.i][current_position.j]->setVehicle(this);
//	cout << "Current Position after: " << current_position.i << ", " << current_position.j << endl;

}

void Vehicles::setPositionJ(int b, PlanetSpot *map[side][side])
{
//	cout << "Current Position before: " << current_position.i << ", " << current_position.j << endl;
	map[current_position.i][current_position.j]->setVehicle(nullptr);
	if (b < 0)
	{
		b = side + b;
	}
	current_position.j = b % side ;
	map[current_position.i][current_position.j]->setVehicle(this);
//	cout << "Current Position after: " << current_position.i << ", " << current_position.j << endl;
}

void Vehicles::setPosition(int a, int b, PlanetSpot *map[side][side])
{
	setPositionI(a, map);
	setPositionJ(b, map);	
}

void Vehicles::setPosition(position pos, PlanetSpot *map[side][side])
{
	setPosition(pos.i, pos.j, map);
}

position Vehicles::move(int go, PlanetSpot *map[side][side])
{
//	printCurrentPosition();
	if(situation==true)
	{
		move_counter++;
	
		switch (go)
		{
			case UP:
				setPositionI(current_position.i-1, map);
				break;

			case DOWN:
				setPositionI(current_position.i+1, map);
				break;

			case LEFT:
				setPositionJ(current_position.j-1, map);
				break;

			case RIGHT:
				setPositionJ(current_position.j+1, map);
				break;

			case UP_LEFT:
				setPositionI(current_position.i-1, map);
				setPositionJ(current_position.j-1, map);
				break;

			case UP_RIGHT:
				setPositionI(current_position.i-1, map);
				setPositionJ(current_position.j+1, map);
				break;

			case DOWN_LEFT:
				setPositionI(current_position.i+1, map);
				setPositionJ(current_position.j-1, map);
				break;

			case DOWN_RIGHT:
				setPositionI(current_position.i+1, map);
				setPositionJ(current_position.j+1, map);
				break;
		
			default:
				cout << "Move function: Wrong arguments. Give a number [0,7]" << endl;

		}//end of switch
		/* stin periptwsi opou to oxima ksepna tin 100 thesi paei stin thesi 0 kathos theoroyme oti o planitis einai strogkilos */
	} //end of if situation==true
	else
	{
		setRoundsWithDamage(getRoundsWithDamage() + 1);
	}
	//	printCurrentPosition();

	return current_position;
} //end of move function

float Vehicles::damage_possibility(PlanetSpot *pls)
{
	return pls->getAccessRisk() * (1-ability); 
}

void Vehicles::printCurrentPosition()
{
	cout << "Vehicles current Position: \n";
	cout << "i = " << current_position.i << endl;
	cout << "j = " << current_position.j << endl;
} //end of printCurrentPosition function

void Vehicles::printInfo()
{
	cout << "Vehicles info: " << endl;
	cout << "Ability: " << ability << endl;
	cout << "Situation: " << situation << endl;
	cout << "Speed: " << speed << endl;
	cout << "Movements: " << move_counter << endl;
	cout << "Damage counter: " << damage_counter << endl;
	printCurrentPosition();
} //end of printInfo fun

void Vehicles::plusDamage()
{
	all_vehicles_damage_counter++;
	damage_counter++;
}

void Vehicles::setRandomAbility()
{
	ability = ( rand() % 100 ) * 0.01; 
}

position Vehicles::getPosition()
{
	return current_position;
}

int Vehicles::getPositionI()
{
	return current_position.i;
}

int Vehicles::getPositionJ()
{
	return current_position.j;
}

void Vehicles::sufferDamage(PlanetSpot *pls)
{
	float p = damage_possibility(pls);
	/* pairnw enan tixaio arithmo anamesa [0,1] kai analoga 
	me to pou einai autos o arithos apofasizw gia to an tha 
	pathei vlavi i oxi */
	float rdm = rand() % 101;
	rdm /= 100;

	if ( rdm < p )
	{
		setSituation(false);
	}
}

void Vehicles::operation(PlanetSpot *map[side][side])
{

}

void Vehicles::setSituation(bool situa)
{
	if(situation == false && situa == true)
	{
		setRoundsWithDamage(0);
		situation = situa;
	}
	else if(situa == false && situation == true)
	{
		situation = situa;
		plusDamage();
	}
}

bool Vehicles::getSituation()
{
 return situation;
}

int Vehicles::getAllVehiclesDamageCounter()
{
	return all_vehicles_damage_counter;
}

void Vehicles::setRoundsWithDamage(int i)
{
	roundsWithDamage = i;
	damage_counter += i;
}

int Vehicles::getRoundsWithDamage()
{
	return roundsWithDamage;
}