#include "analyst.h"

int Analyst:: all_cargo = 0;


Analyst::Analyst(bool sit, float abil, int sp, int a, int b, int cargo_pall, int cargo_irid, int cargo_lefk) : Vehicles(sit , abil, sp, a, b)
{
	max_product = 100;
	cargo_palladio = cargo_pall;
	cargo_iridio = cargo_irid;
	cargo_lefkoxrisos = cargo_lefk;
}

Analyst::~Analyst()
{
	printInfo();
	cout << "DELETED \n";
}

void Analyst::printInfo()
{
	cout << "Analyst: \n";
	Vehicles::printInfo();
	cout << "max product: " << max_product << endl;
	cout << "cargo palladio: " << cargo_palladio << endl;
	cout << "cargo iridio: " << cargo_iridio << endl;
	cout << "cargo lefkoxrisos: " << cargo_lefkoxrisos << endl;
}

void Analyst::plusCargo()
{
	all_cargo += ( cargo_iridio + cargo_lefkoxrisos + cargo_palladio );
}

int Analyst::getCargo()
{
	return cargo_iridio + cargo_lefkoxrisos + cargo_palladio;
}

void Analyst::freeCargo()
{
	cargo_iridio = 0;
	cargo_lefkoxrisos = 0;
	cargo_palladio = 0;
}

void Analyst::operation(PlanetSpot *map[side][side])
{
	if( map[current_position.i][current_position.j]->getSumContent() > 60 ) //epilegoume na kanoume tin eksoriksi ean i periektikotita einai >60
	{
		sufferDamage(map[current_position.i][current_position.j]); //kaloume tin sufferDamage i opoia apofasizei gia to an tha ginei vlavi i oxi
		if( situation==true ) //elenxw an exei vlavi to oxima
		{
			cout << "- - -\nAnalyst before extraction: \n";
			printInfo();
			if(getCargo() + map[current_position.i][current_position.j]->getIridius() <= max_product)
			{
				cargo_iridio += map[current_position.i][current_position.j]->getIridius(); //vazoume sto oxima to iridio
				map[current_position.i][current_position.j]->removeIridius(); //to afairoume apo to simeio sto xarti
			}
			else
			{
				int temp = max_product - getCargo(); //apothikevoume se mia prosorini metavliti to fortio opoy tha ginei eksoriksi
				cargo_iridio += max_product - getCargo(); //vazoume sto oxima oso iridio mporei na parei
				map[current_position.i][current_position.j]->removeIridius(temp); //afairoume apo to simeio sto xarti to idirio to opoio pirame
			}
			if(getCargo() + map[current_position.i][current_position.j]->getLefkoxrisos() <= max_product)
			{
				cargo_lefkoxrisos += map[current_position.i][current_position.j]->getLefkoxrisos(); //vazoume sto oxima to lefkoxriso
				map[current_position.i][current_position.j]->removeLefkoxrisos(); //to afairoume apo to simeio
			}
			else
			{
				int temp = max_product - getCargo(); //apothikevoume se mia prosorini metavliti to fortio opoy tha ginei eksoriksi
				cargo_lefkoxrisos += max_product - getCargo(); //vazoume sto oxima oso lefkoxriso mporei na kouvalisei
				map[current_position.i][current_position.j]->removeLefkoxrisos(temp); //afairoume tin posotita opou eksoriksame apo to simeio
			}
			if(getCargo() + map[current_position.i][current_position.j]->getPaladio() <= max_product)
			{
				cargo_palladio += map[current_position.i][current_position.j]->getPaladio(); //vazoume sto oxima to paladio
				map[current_position.i][current_position.j]->removePaladius(); //to aferoume apo to simeio
			}
			else
			{
				int temp = max_product - getCargo(); //apothikevoume se mia prosorini metavliti to fortio opoy tha ginei eksoriksi
				cargo_palladio += max_product - getCargo(); //vazoume sto oxima oso palladio mporei na kouvalisei
				map[current_position.i][current_position.j]->removePaladius(temp); //to afairoume apo to simeio sto xarti
			}
			all_cargo += cargo_iridio + cargo_lefkoxrisos + cargo_palladio;

			cout << "\nAnalyst after extraction: \n";
			printInfo();
			cout << "- - - \n";
			/*To oxima metaferete stin vasi*/
			if( max_product == getCargo() )
			{
				map[current_position.i][current_position.j]->setVehicle(nullptr); //vgazw to oxima apo simeio
				current_position = map[current_position.i][current_position.j]->getBasePos(); //stelnw to oxima sti vasi
				map[current_position.i][current_position.j]->setVehicle(this); // vazw sti vasi to oxima
				
				/*vazw ta 3 sistatika sti vasi*/
				map[PlanetSpot::getBasePosI()][PlanetSpot::getBasePosJ()]->addPaladio(cargo_palladio);
				map[PlanetSpot::getBasePosI()][PlanetSpot::getBasePosJ()]->addIridio(cargo_iridio);
				map[PlanetSpot::getBasePosI()][PlanetSpot::getBasePosJ()]->addLefkoxrisos(cargo_lefkoxrisos);
				
				freeCargo(); //adiazw to fortio apo to oxima
			}
		} //end of if situation==true
		else
		{
			setRoundsWithDamage(getRoundsWithDamage() + 1);
		}
	}
	
	
	
}
