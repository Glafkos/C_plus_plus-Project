# include <iostream>
# include <time.h>
# include "analyst.h"
# include "explorer.h"
# include "rescuer.h"
# include "PlanetSpot.h"
# include "main.h"
# include <cstdlib>
# include "move_vehicles.h"
# include <vector>
# include <string>

using namespace std;

int main()
{
	srand(time(NULL));
	system("cls");
	system("color A");

	cout << "Welcome \n";
	cout << "Press any key to create the map! \n";
	system("pause > nul");

	/*Orizoume ton xarti*/
	PlanetSpot *map[side][side];

	/* creating the map */
	for(int i=0; i<side; i++)
	{
		for (int j=0; j<side; j++)
		{
			map[i][j] = new PlanetSpot(i, j);
			map[i][j]->setRandomContents();
			map[i][j]->setRandomAccessRisk();
		}
	}
	
	/* thetw thesi sti vasi */
	PlanetSpot::setBasePos(getRandomPosition());
	
	map[PlanetSpot::getBasePosI()][PlanetSpot::getBasePosJ()]->setBase(true);


	//cout << "\nMap created!! \n\n";
	cout << "Press any key to create the vehicles. \nWe create "<< DEF_VEH_NUM << " vehicles\n";
	cout << " " << DEF_ANAL_NUM << " analysts \n";
	cout << " " << DEF_RES_NUM << " rescuers \n";
	cout << " " << DEF_EX_NUM << " explorers \n";
	system("pause > nul");
	
	vector< Vehicles* > veh_vector;

	veh_vector = initRandomVehicles(DEF_ANAL_NUM, DEF_RES_NUM, DEF_EX_NUM, map);
	cout << "Vehicles are ready!\n";

	int option = menu(veh_vector, map, "start");

	int rounds=0;

	while (option == 0)
	{
		cout << "\n/**********************************************\\ \n";
		cout << "ROUND: " << rounds+1 << endl;
		vector< Vehicles* > :: iterator veh_iter;
		if( rounds % 2 == 0 )
		{
			for(veh_iter=veh_vector.begin(); veh_iter!=veh_vector.end(); veh_iter++)
			{
				moveVehiclesRandom(*veh_iter, map);
			}
		}
		else
		{
			for(veh_iter=veh_vector.begin(); veh_iter!=veh_vector.end(); veh_iter++)
			{
				(*veh_iter)->operation(map);
			}
		}
		cout << "/**********************************************\\ \n";
		
		checkVehiclesToRemove(veh_vector, map);
		
		EndProgram(map, veh_vector);

		option = menu(veh_vector, map, "continue");
		rounds++;
}
	
	/* prepei na valw na diagrafontai ta oximata opoy deixnei o vector! */
	system("pause");
	return 0;
}



