#pragma once

#include "position.h"
#include "PlanetSpot.h"
#include "vehicles.h"
#include <vector>
#include <string>

# define DEF_ANAL_NUM 3
# define DEF_EX_NUM 3
# define DEF_RES_NUM 3
# define DEF_VEH_NUM DEF_RES_NUM+DEF_EX_NUM+DEF_ANAL_NUM
# define MAXBASE 1000
# define MAX_ROUNDS_WITH_DAMAGE 15

using namespace std;

position getRandomPosition()
{
	position p;
	p.i = rand() % side;
	p.j = rand() % side;
	return p;
}; //end of getRandomPosiotion

position getFreeRandomPosition(PlanetSpot *map[side][side])
{
	position p;
	do
	{
		p = getRandomPosition();
	}
	while (map[p.i][p.j]->getVehicle() != nullptr);
	return p;
}; //end of getFreeRandomPosition

vector< Analyst* > initRandomAnalyst(unsigned number, PlanetSpot *map[side][side])
{
	vector< Analyst* > anal_vector;

	for(int i=0; i<number; i++)
	{
		position p = getFreeRandomPosition( map );
		anal_vector.push_back( new Analyst(true, 0.5, 50, p.i, p.j) );
		map[p.i][p.j]->setVehicle( anal_vector[i] );
	}

	return anal_vector;
}; //end of initRandomAnalyst

vector< Rescuer* > initRandomRescuer(unsigned number, PlanetSpot *map[side][side])
{
	vector< Rescuer* > res_vector;

	for(int i=0; i<number; i++)
	{
		position p = getFreeRandomPosition(map);
		res_vector.push_back( new Rescuer(true, 0.5, 50, p.i, p.j) );
		map[p.i][p.j]->setVehicle( res_vector[i] );
	}

	return res_vector;
}; //end of initRandomRescuer

vector< Explorer* > initRandomExplorer(unsigned number, PlanetSpot *map[side][side])
{
	vector< Explorer* > ex_vector;

	for(int i=0; i<number; i++)
	{
		position p = getFreeRandomPosition(map);
		ex_vector.push_back( new Explorer(true, 0.5, 50, p.i, p.j) );
		map[p.i][p.j]->setVehicle( ex_vector[i] );
	}

	return ex_vector;
}; //end of initRandomRescuer

vector< Vehicles* > initRandomVehicles(unsigned anal_number, unsigned res_number, unsigned ex_number, PlanetSpot *map[side][side])
{
	/* ftiaxnoume ta oximata */
	vector< Vehicles* > veh_vector;
	vector< Analyst* > anal_vector;
	vector< Explorer* > ex_vector;
	vector< Rescuer* > res_vector;

	anal_vector = initRandomAnalyst(DEF_ANAL_NUM, map);
	res_vector = initRandomRescuer(DEF_RES_NUM, map);
	ex_vector = initRandomExplorer(DEF_EX_NUM, map);

	for(int i=0; i<anal_number; i++)
	{
		veh_vector.push_back( anal_vector[i] );
	}
	for(int i=0; i<res_number; i++)
	{
		veh_vector.push_back( res_vector[i] );
	}
	for(int i=0; i<ex_number; i++)
	{
		veh_vector.push_back( ex_vector[i] );
	}

	return veh_vector;
}; //end of initRandomVehicles

void addNewAnalystFromUser(vector< Vehicles* > &anal_vector, PlanetSpot *map[side][side], bool sit, float abil, int sp, int i, int j)
{
	int cargo_pall, cargo_irid, cargo_lefk;

	cout << "Set palladius cargo : ";
	cin >> cargo_pall;
	while (cargo_pall < 0 || cargo_pall > 100)
	{
		cout << "Please give a correct value! \n";
		cout << "Set palladius cargo : ";
		cin >> cargo_pall;
	}

	cout << "Set iridius cargo : ";
	cin >> cargo_irid;
	while (cargo_irid < 0 || cargo_irid > 100)
	{
		cout << "Please give a correct value! \n";
		cout << "Set iridius cargo : ";
		cin >> cargo_irid;
	}

	cout << "Set platinum cargo : ";
	cin >> cargo_lefk;
	while (cargo_lefk < 0 || cargo_lefk > 100)
	{
		cout << "Please give a correct value! \n";
		cout << "Set iridius cargo : ";
		cin >> cargo_lefk;
	}

	anal_vector.push_back( new Analyst(sit, abil, sp, i, j, cargo_pall, cargo_irid, cargo_lefk) );
	map[i][j]->setVehicle( anal_vector.back() );
} //end of addNewAnalystFromUser

void addNewExplorerFromUser(vector< Vehicles* > &ex_vector, PlanetSpot *map[side][side], bool sit, float abil, int sp, int i, int j)
{
	ex_vector.push_back( new Explorer(sit, abil, sp, i, j) );
	map[i][j]->setVehicle( ex_vector.back() );
} // end of addNewExplorerFromUser

void addNewRescuerFromUser(vector< Vehicles* > &res_vector, PlanetSpot *map[side][side], bool sit, float abil, int sp, int i, int j)
{
	res_vector.push_back( new Rescuer(sit, abil, sp, i, j) );
	map[i][j]->setVehicle( res_vector.back() );
} //end of addNewRescuerFromUser

void addNewVehicleFromUser(vector< Vehicles* > &veh_vector, PlanetSpot *map[side][side])
{
	char input;
	bool sit;
	float abil;
	int sp;
	int i,j;

	cout << "Create a new Vehicle: \n";
	
	cout << "Set situation (for true press t and for false press f): ";
	cin >> input;
	while (input!='t' && input!='f')
	{
		cout << "Please give a correct value! \n";
		cout << "Set situation (for true press t and for false press f): ";
		cin >> input;
	}
	if(input=='f')
	{
		sit = false;
	}
	else
	{
		sit = true;
	}
	
	cout << "Set ability [0.0, 0.9] : ";
	cin >> abil;
	while (abil < 0 || abil > 0.9)
	{
		cout << "Please give a correct value! \n";
		cout << "Set ability [0.0, 0.9] : ";
		cin >> abil;
	}

	cout << "Set Speed [0, 100] : ";
	cin >> sp;
	while (sp < 0 || sp > 100)
	{
		cout << "Please give a correct value! \n";
		cout << "Set Speed [0, 100] : ";
		cin >> sp;
	}

	bool ask_again_position;
	do
	{
		ask_again_position = false;
		cout << "Set Position (side[0, " << side-1 << "]) : \n";
		cout << "i = ";
		cin >> i;
		while (i<0 || i>=side)
		{
			cout << "Please give a correct value! \n";
			cout << "i is [0, " << side-1 << "] : \n";
			cin >> i;
		}
		cout << "j = ";
		cin >> j;
		while (j<0 || j>=side)
		{
			cout << "Please give a correct value! \n";
			cout << "j is [0, " << side-1 << "] : \n";
			cin >> j;
		}
		
		if(map[i][j]->getAvailable()==false)
		{
			ask_again_position = true;
			cout << "This position is not Available! \n";
		}
		else if(map[i][j]->getVehicle()!=nullptr)
		{
			ask_again_position = true;
			cout << "There is another vehicle there! \n";
		}
		//prepei na kanw kai setVehicle sto map[i][j] otan prosdiorisw ton tipo tou oximatos
	}while(ask_again_position == true);

	cout << "Choose type for the vehicle : \n 1 - Analyst \n 2 - Explorer \n 3 - Rescuer \n";
	int x;
	cin >> x;
	while (x<0 || x>3)
	{
		cout << "Please give a correct value! \n";
		cout << "Choose type for the vehicle : \n 1 - Analyst \n 2 - Explorer \n 3 - Rescuer \n";
		int x;
	}
	if (x == 1)
	{
		addNewAnalystFromUser(veh_vector, map, sit, abil, sp, i, j);
	}
	else if (x == 2)
	{
		addNewExplorerFromUser(veh_vector, map, sit, abil, sp, i, j);
	}
	else if (x == 3)
	{
		addNewRescuerFromUser(veh_vector, map, sit, abil, sp, i, j);
	}
} //addNewVehicleFromUser

void editSituation(PlanetSpot *map[side][side]) //epexergasia katastasis oximatos
{
	char situation;
	int i, j;
	cout << "Select vehicle for change situation from map by coordinates:\n"; //epilogi oximatos apo sintetagmenes
	bool ask_again_position;
	
	do
	{
		ask_again_position = false;
		cout << "Vehicle position Position (side[0, " << side - 1 << "] : \n";
		cout << "i = ";
		cin >> i;
		while (i < 0 || i >= side)
		{
			cout << "Please give a correct value! \n";
			cout << "i is [0, " << side - 1 << "] : \n";
			cin >> i;
		}
		cout << "j = ";
		cin >> j;
		while (j < 0 || j >= side)
		{
			cout << "Please give a correct value! \n";
			cout << "j is [0, " << side - 1 << "] : \n";
			cin >> j;
		}
		
		if (map[i][j]->getVehicle() == nullptr)
		{
			ask_again_position = true;
			cout << "This position not have vehicle! \n";
		}
	} while (ask_again_position == true);
	
	cout << "Edit situation (for true press t and for false press f): ";
	cout << "The current situation is : " << map[i][j]->getVehicle()->getSituation() << endl;
	cin >> situation;
	while (situation != 't' && situation != 'f')
	{
		cout << "Please give a correct value! \n";
		cout << "Edit situation (for true press t and for false press f): ";
		cin >> situation;
	}
	if (situation == 'f')
	{
		map[i][j]->getVehicle()->setSituation(false);
	}
	else if (situation == 't')
	{
		map[i][j]->getVehicle()->setSituation(true);
	}
} //end of edit situation

void printBaseInfo(PlanetSpot *map[side][side])
{
	cout << "Base Info : \n";
	cout << "Position: " << map[0][0]->getBasePosI() << ", " << map[0][0]->getBasePosJ() << endl;
	cout << "Palladium 's content: " << map[PlanetSpot::getBasePosI()][PlanetSpot::getBasePosJ()]->getPaladio() << endl;
	cout << "Platinum 's content: " << map[PlanetSpot::getBasePosI()][PlanetSpot::getBasePosJ()]->getLefkoxrisos() << endl;
	cout << "Iridium 's content: " << map[PlanetSpot::getBasePosI()][PlanetSpot::getBasePosJ()]->getIridius() << endl;
}

void editSpot(PlanetSpot *map[side][side])
{
	int i,j;
	cout << "Choose the coordinates of the map that you want to edit: \n";
	cout << "i = ";
	cin >> i;
	while (i < 0 || i >= side)
	{
		cout << "Please give a correct value! \n";
		cout << "i is [0, " << side - 1 << "] : \n";
		cin >> i;
	}
	cout << "j = ";
	cin >> j;
	while (j < 0 || j >= side)
	{
		cout << "Please give a correct value! \n";
		cout << "j is [0, " << side - 1 << "] : \n";
		cin >> j;
	}

	cout << "You choose to edit : \n";
	map[i][j]->printInfo();
	cout << "`'`'`'`'`'`'`'`'`'`'`'\n";

	int cont_pall=0, cont_irid=0, cont_lefk=0;
	cout << "Give new value for paladius : ";
	cin >> cont_pall;
	while (cont_pall < 0 || cont_pall > 100 - cont_lefk - cont_irid)
	{
		cout << "Please give a correct value! \n";
		cout << "Palladius must be [0," << 100 - cont_lefk - cont_irid << "] : ";
		cin >> cont_pall;
	}
	map[i][j]->setPaladio(cont_pall);

	cout << "Give new value for iridius : ";
	cin >> cont_irid;
	while (cont_irid < 0 || cont_irid > 100 - cont_lefk - cont_pall)
	{
		cout << "Please give a correct value! \n";
		cout << "Iridius must be [0," << 100 - cont_lefk - cont_pall << "] : ";
		cin >> cont_irid;
	}
	map[i][j]->setIridio(cont_irid);

	cout << "Give new value for platinum : ";
	cin >> cont_lefk;
	while (cont_lefk < 0 || cont_lefk > 100 - cont_pall - cont_irid)
	{
		cout << "Please give a correct value! \n";
		cout << "Platinum must be [0," << 100 - cont_pall - cont_irid << "] : ";
		cin >> cont_lefk;
	}
	map[i][j]->setLefkoxisos(cont_lefk);

	float accessRisk;
	cout << "Give new value for access risk : ";
	cin >> accessRisk;
	while (accessRisk < 0 || accessRisk > 1)
	{
		cout << "Please give a correct value! \n";
		cout << "Access Risk [0,1] : ";
		cin >> accessRisk;
	}
	map[i][j]->setAccessRisk(accessRisk);


	char riskFlag;
	cout << "Put or remove Risk Flag (for true press t and for false press f): ";
	cin >> riskFlag;
	while (riskFlag != 't' && riskFlag != 'f')
	{
		cout << "Please give a correct value! \n";
		cout << "Put or remove Risk Flag (for true press t and for false press f): ";
		cin >> riskFlag;
	}
	if (riskFlag == 'f')
	{
		map[i][j]->setRiskFlag(false);
	}
	else if (riskFlag == 't')
	{
		map[i][j]->setRiskFlag(true);
	}
} //end of editSpot

void printOptionsForMenu(string str)
{
	cout << "\n\nPress: \n 1: To print Vehicles info\n"; 
	cout <<	" 2: To print planet spots info \n";
	cout << " 3: To add new vehicle \n";
	cout << " 4: To edit vehicles situation \n";
	cout << " 5: To print base info \n";
	cout << " 6: To print damage counter for all vehicles \n";
	cout << " 7: To print count of flags \n";
	cout << " 8: To edit a planet spot \n";
	cout << " 9: To end the program \n";
	cout << " 0: To " << str << " the simulation \n" << endl;
} //end of printOptionsForMenu

int menu(vector< Vehicles* > &veh_vector, PlanetSpot *map[side][side], string str)
{
	int option;
	
	printOptionsForMenu(str);
	
	cin >> option;
	while (option<0 || option>9)
	{
		cout << "Please insert a correct value! \n";

		printOptionsForMenu(str);

		cin >> option;
	}
	
	while(option != 0)
	{
		vector< Vehicles* > :: iterator veh_iter;
		switch (option)
		{
		case 1:
			for (veh_iter=veh_vector.begin(); veh_iter!=veh_vector.end(); veh_iter++)
			{
				cout << "\n";
				(*veh_iter)->printInfo();
			}
			break;

		case 2:
			for (int i=0; i<side; i++)
			{
				for(int j=0; j<side; j++)
				{
					cout << "\n";
					map[i][j]->printInfo();
				}
			}
			break;
		
		case 3:
			addNewVehicleFromUser(veh_vector, map);
			break;

		case 4:
			editSituation(map);
			break;

		case 5:
			printBaseInfo(map);
			break;

		case 6:
			cout << "\nÇave occurred " << Vehicles::getAllVehiclesDamageCounter() << " damages to vehicles \n";
			break;

		case 7:
			cout << "\nExplorers have putted " << Explorer::getAllFlagCounter() << " flags \n";
			break;

		case 8:
			editSpot(map);
			break;

		case 9: 
			return 1;
			break;

		case 0:
			cout << "You choose to " << str << " the simulation!!! \n" << endl;
			break;

		default:
			cout << "Value ERROR \n";
			return 100;
		}
		
		printOptionsForMenu(str);

		cin >> option;
		while (option<0 || option>9)
		{
			cout << "Insert a correct value! \n";
			
			printOptionsForMenu(str);

			cin >> option;
		}
	}

	return option;
} //end of menu

void checkVehiclesToRemove(vector< Vehicles* > &veh_vector, PlanetSpot *map[side][side])
{
	vector< Vehicles* > :: iterator veh_iter;
	for(veh_iter=veh_vector.begin(); veh_iter!=veh_vector.end(); veh_iter++)
	{
		if ( (*veh_iter)->getRoundsWithDamage() > MAX_ROUNDS_WITH_DAMAGE )
		{
			map[(*veh_iter)->getPositionI()][(*veh_iter)->getPositionJ()]->setVehicle(nullptr);
			delete (*veh_iter);
			veh_iter = veh_vector.erase( veh_iter );
		}
	}
} //end of checkVehiclesToRemove

int EndProgram(PlanetSpot *map[side][side], vector< Vehicles* > &veh_vector)
{
	if (map[PlanetSpot::getBasePosI()][PlanetSpot::getBasePosJ()]->getSumContent() >= MAXBASE)
	{
		cout << "Well Done!!!!!" << endl;
		system("pause");
		exit(1);
	}

	vector< Vehicles* > ::iterator veh_iter;
	bool flag = true;

	for (veh_iter = veh_vector.begin(); veh_iter != veh_vector.end(); veh_iter++)
	{
		if ((*veh_iter)->getSituation() == true)
		{
			flag = false;
		}
	}

	if (flag == true)
	{
		cout << "Loser! All vehicles have damage!!!" << endl;
		system("pause");
		exit(1);
	}

} // end program()