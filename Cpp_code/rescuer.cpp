#include "rescuer.h"

Rescuer :: Rescuer(bool sit, float abil, int sp, int a, int b) : Vehicles(sit , abil, sp, a, b)
{
	fixCounter = 0;
}

Rescuer :: ~Rescuer()
{
	cout << "Rescuer: \n";
	printInfo();
	cout << "DELETED!!";
}

void Rescuer :: printInfo()
{
	cout << "Rescuer: \n";
	Vehicles::printInfo();
	cout << "fix counter: " << fixCounter << endl;
}

void Rescuer::operation(PlanetSpot *map[side][side])
{
	/* apothikevw tin trexousa thesi se mia prosorini topiki metavliti */
	position temp_pos = current_position;

	/*elegxi to aristera panw diagwnia panelSpot*/
	if (temp_pos.i-1 < 0) temp_pos.i += side-1; //elenxw an ksepernaei ta oria tou pinaka => i = i - 1
	if (temp_pos.j-1 < 0) temp_pos.j += side-1; //elenxw an ksepernaei ta oria tou pinaka => j = j - 1
	if( map[temp_pos.i][temp_pos.j]-> getVehicle() != nullptr ) //(i-1, j-1)
	{
		Vehicles *v;
		v = map[temp_pos.i][temp_pos.j]->getVehicle();

		if (v->getSituation() == false)
		{
			v->setSituation(true);
			fixCounter += 1;
			cout << "- - -\nRescuer fixed a vehicle at: ";
			v->printCurrentPosition();
			cout << "- - - \n";
		}
	}
	/*elegxi to apo panw panelSpot*/
	// i = i - 1
	// j = j - 1
	if( map[temp_pos.i][current_position.j]->getVehicle() != nullptr ) //(i-1, j) 
	{
		Vehicles *v = map[temp_pos.i][current_position.j]->getVehicle();
		
		if (v->getSituation() == false)
		{
			v->setSituation(true);
			fixCounter += 1;
			cout << "- - -\nRescuer fixed a vehicle at: ";
			v->printCurrentPosition();
			cout << "- - - \n";
		}
	}
	/*elegxi to aristera panelSpot*/
	// i = i - 1
	// j = j - 1
	if( map[current_position.i][temp_pos.j]->getVehicle() != nullptr ) //(i, j-1)
	{
		Vehicles *v = map[current_position.i][temp_pos.j]->getVehicle();
		
		if (v->getSituation() == false)
		{
			v->setSituation(true);
			fixCounter += 1;
			cout << "- - -\nRescuer fixed a vehicle at: ";
			v->printCurrentPosition();
			cout << "- - - \n";
		}
	}
	
	/*elegxi to dexia panw diagwnia panelSpot*/
	temp_pos.j = (current_position.j+1) % side; //elenxw an pernaw ta oria tou side
	// i = i - 1
	// j = j + 1
	if( map[temp_pos.i][temp_pos.j]->getVehicle() != nullptr ) //(i-1, j+1)
	{
		Vehicles *v = map[temp_pos.i][temp_pos.j]->getVehicle();
		
		if (v->getSituation() == false)
		{
			v->setSituation(true);
			fixCounter += 1;
			cout << "- - -\nRescuer fixed a vehicle at: ";
			v->printCurrentPosition();
			cout << "- - - \n";
		}
	}
	/*elegxi to dexia panelSpot*/
	// i = i - 1
	// j = j + 1
	if( map[current_position.i][temp_pos.j]->getVehicle() != nullptr ) //(i, j+1)
	{
		Vehicles *v = map[current_position.i][temp_pos.j]->getVehicle();
		
		if (v->getSituation() == false)
		{
			v->setSituation(true);
			fixCounter += 1;
			cout << "- - -\nRescuer fixed a vehicle at: ";
			v->printCurrentPosition();
			cout << "- - - \n";
		}
	}
	
	/*elegxi to aristera katw diagwnia panelSpot*/
	temp_pos.i = (temp_pos.i+1) % side;
	temp_pos.j = current_position.j - 1;
	if (temp_pos.j < 0) temp_pos.j += side-1; 
	// i = i + 1
	// j = j - 1
	if( map[temp_pos.i][temp_pos.j]->getVehicle() != nullptr ) //(i+1, j-1)
	{
		Vehicles *v = map[temp_pos.i][temp_pos.j]->getVehicle();
		
		if (v->getSituation() == false)
		{
			v->setSituation(true);
			fixCounter += 1;
			cout << "- - -\nRescuer fixed a vehicle at: ";
			v->printCurrentPosition();
			cout << "- - - \n";
		}
	}
	
	/*elegxi to katw panelSpot*/
	// i = i + 1
	// j = j - 1
	if( map[temp_pos.i][current_position.j]->getVehicle() != nullptr ) //(i+1, j)
	{
		Vehicles *v = map[temp_pos.i][current_position.j]->getVehicle();
		
		if (v->getSituation() == false)
		{
			v->setSituation(true);
			fixCounter += 1;
			cout << "- - -\nRescuer fixed a vehicle at: ";
			v->printCurrentPosition();
			cout << "- - - \n";
		}
	}
	
	/*elegxi to dexia katw diagwnia panelSpot*/
	temp_pos.j = (current_position.j + 1) % side;
	// i = i + 1
	// j = j + 1
	if( map[temp_pos.i][temp_pos.j]->getVehicle() != nullptr ) //(i+1, j+1)
	{
		Vehicles *v = map[temp_pos.i][temp_pos.j]->getVehicle();
		
		if (v->getSituation() == false)
		{
			v->setSituation(true);
			fixCounter += 1;
			cout << "- - -\nRescuer fixed a vehicle at: ";
			v->printCurrentPosition();
			cout << "- - - \n";
		}
	
}



}