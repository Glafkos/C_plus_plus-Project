#include "explorer.h"

int Explorer::all_flag_counter = 0;

 Explorer:: Explorer(bool sit, float abil, int sp, int a, int b) : Vehicles(sit , abil, sp, a, b)
{
	flagCounter = 0;
}

 Explorer::~Explorer()
{
	cout << "Explorer : \n";
	Vehicles::printInfo();
	cout << "DELETED \n";
}

 void Explorer::printInfo()
 {
	 cout << "Explorer: \n";
	 Vehicles::printInfo();
	 cout << "Flags counter: " << flagCounter << endl;
 }

 void Explorer::operation(PlanetSpot *map[side][side])
 {
	 if(situation == true)
	 {
		 if( map[current_position.i][current_position.j]->hasRiskFlag() == false )
		{
			 if ( map[current_position.i][current_position.j]->getAccessRisk() >= HIGH_ACCESS_RISK )
			 {
				 map[current_position.i][current_position.j]->setRiskFlag( true );
				 map[current_position.i][current_position.j]->setAvailable(false);
				 plusFlagCounter();
				 cout << "Risk flag putted at: " << endl;
				 map[current_position.i][current_position.j]->printInfo();
			 }
		 }
	 }//end of if situation==true
	else
	{
		setRoundsWithDamage(getRoundsWithDamage() + 1);
	}
 }

 void Explorer::plusFlagCounter()
 {
	 all_flag_counter++;
	 flagCounter++;
 }

 int Explorer::getAllFlagCounter()
 {
	 return all_flag_counter;
 }
