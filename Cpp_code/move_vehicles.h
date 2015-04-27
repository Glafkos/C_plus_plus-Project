#pragma once
#include "vehicles.h"

/* metakinei to oxeima gia to opoio kaleite se tixaia thesi mono ean i thesi i opoia zititai einai diathesimi */
void moveVehiclesRandom(Vehicles *veh, PlanetSpot *map[side][side])
{
	if(veh->getSituation() == true)
	{
		int go = rand() % 8;

		position current_position = veh->getPosition();

		switch (go)
		{
			case UP:
				if ( current_position.i-1 < 0 ) //elegxoume an vgeinei apo ta panw oria tou pinaka paei katw
				{
					current_position.i += side-1;
				}
				if ( (map[current_position.i][current_position.j] -> getAvailable()) == true && map[current_position.i][current_position.j]->getVehicle() == nullptr)
				{
					cout << "Vehicle moved from position (" << veh->getPositionI() << ", " << veh->getPositionJ() << ") to position (";
					veh->move(UP, map);
					cout << veh->getPositionI() << ", " << veh->getPositionJ() << ") \n";
				}
				break;

			case DOWN:
				current_position.i++; //otan bgainei apo ta katw oria toy pinaka paei panw
				current_position.i %= side;
				if ( (map[current_position.i][current_position.j] -> getAvailable()) == true && map[current_position.i][current_position.j]->getVehicle() == nullptr)
				{
					cout << "Vehicle moved from position (" << veh->getPositionI() << ", " << veh->getPositionJ() << ") to position (";
					veh->move(DOWN, map);
					cout << veh->getPositionI() << ", " << veh->getPositionJ() << ") \n";
				}
				break;

			case LEFT:
				if ( current_position.j-1 < 0 ) //an bgei apo ta aristera oria tou pinaka paei deksia
				{
					current_position.j += side-1;
				}
				if ( (map[current_position.i][current_position.j] -> getAvailable()) == true && map[current_position.i][current_position.j]->getVehicle() == nullptr)
				{
					cout << "Vehicle moved from position (" << veh->getPositionI() << ", " << veh->getPositionJ() << ") to position (";
					veh->move(LEFT, map);
					cout << veh->getPositionI() << ", " << veh->getPositionJ() << ") \n";
				}
				break;

			case RIGHT:
				++current_position.j %= side ; //an kseperasoume ta oria tou pinaka apo deksia paei aristera
				if ( (map[current_position.i][current_position.j] -> getAvailable()) == true && map[current_position.i][current_position.j]->getVehicle() == nullptr)
				{
					cout << "Vehicle moved from position (" << veh->getPositionI() << ", " << veh->getPositionJ() << ") to position (";
					veh->move(RIGHT, map);
					cout << veh->getPositionI() << ", " << veh->getPositionJ() << ") \n";
				}
				break;

			case UP_LEFT:
				if ( current_position.i-1 < 0 )
				{
					current_position.i += side-1;
				}
				if ( current_position.j-1 < 0 )
				{
					current_position.j += side-1;
				}
				if ( (map[current_position.i][current_position.j] -> getAvailable()) == true && map[current_position.i][current_position.j]->getVehicle() == nullptr)
				{
					cout << "Vehicle moved from position (" << veh->getPositionI() << ", " << veh->getPositionJ() << ") to position (";
					veh->move(UP_LEFT, map);
					cout << veh->getPositionI() << ", " << veh->getPositionJ() << ") \n";
				}
				break;

			case UP_RIGHT:
				if ( current_position.i-1 < 0 )
				{
					current_position.i += side-1;
				}
				++current_position.j %= side ;
				if ( (map[current_position.i][current_position.j] -> getAvailable()) == true && map[current_position.i][current_position.j]->getVehicle() == nullptr)
				{
					cout << "Vehicle moved from position (" << veh->getPositionI() << ", " << veh->getPositionJ() << ") to position (";
					veh->move(UP_RIGHT, map);
					cout << veh->getPositionI() << ", " << veh->getPositionJ() << ") \n";
				}
				break;

			case DOWN_LEFT:
				++current_position.i %= side;
				if ( current_position.j-1 < 0 )
				{
					current_position.j += side-1;
				}

				if ( (map[current_position.i][current_position.j] -> getAvailable()) == true && map[current_position.i][current_position.j]->getVehicle() == nullptr)
				{
					cout << "Vehicle moved from position (" << veh->getPositionI() << ", " << veh->getPositionJ() << ") to position (";
					veh->move(DOWN_LEFT, map);
					cout << veh->getPositionI() << ", " << veh->getPositionJ() << ") \n";
				}
				break;

			case DOWN_RIGHT:
				++current_position.i %= side;
				++current_position.j %= side ;

				if ( (map[current_position.i][current_position.j] -> getAvailable()) == true && map[current_position.i][current_position.j]->getVehicle() == nullptr)
				{
					cout << "Vehicle moved from position (" << veh->getPositionI() << ", " << veh->getPositionJ() << ") to position (";
					veh->move(DOWN_RIGHT, map);
					cout << veh->getPositionI() << ", " << veh->getPositionJ() << ") \n";
				}
				break;
		
			default:
				cout << "Moving Vehicles in random position ERROR! \n";
				break;


		}//end of switch
	} //end of if(veh->getSituation() == true)
	else
	{
		veh->setRoundsWithDamage( veh->getRoundsWithDamage() + 1 );
	}
}