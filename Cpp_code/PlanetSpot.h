class Vehicles;
#pragma once
#define PlanetSpot_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "position.h"

#define HIGH_ACCESS_RISK 0.6
#define side 10

using namespace std;

class PlanetSpot
{
	protected:
		int content_palladio; /* periextikotita palladiou */
		int content_iridio;	/* periextikotita iridiou */
		int content_lefkoxrisos; /*periextikotita lefkoxrisou*/
		float access_risk;		/* epikindinotita prosvasis [0.0, 0.9] oso megaliteri toso pithanotero vlavi sto oxima */
		bool risk_flag;		/* simaia kindinou pou simatodoti epikindini thesi */
		position pos;		/* simia sto planet */
		
	public:
		PlanetSpot(int a=0, int b=0, bool risk_fl=false, float acc_risk=0, int cont_lefk=0, int cont_irid=0, int cont_pall=0);
		~PlanetSpot();
		
		void printInfo(); //tipwnei tis plirofories

		float getAccessRisk(); //epistrefei float [0.0, 0.9] tin epikindinotita prosvasis
		int getSumContent(); //epistrefei to athrisma twn periektotitwn

		bool hasRiskFlag(); //leei an exei simaia kindinou i oxi
		void setRiskFlag(bool flag=false); //topothetei simaies kindinou
	
		void calculate_risk_sum(); 
		float get_risk_average();

		void setRandomContents(); //arxikopoiw tis periektikotites me tixaies times
		void setRandomAccessRisk(); //arxikopoiw tin epikindinotita. Peripou 30% true

		void setAvailable(bool av=true);
		bool getAvailable();

		void setBase(bool=true); //orizei thesi an iparxei vasi i oxi kai an nai tote arxikopoiei ta sistatika me 0
		bool getBase(); //epistrefei ena boolean to opoia dilwnei an iparxei vasi i oxi

		int getPaladio();
		int getIridius();
		int getLefkoxrisos();

		void setPaladio(int pal);
		void setIridio(int ir);
		void setLefkoxisos(int lefk);
		void setAccessRisk(float access_risk);

		void addIridio(int ir);
		void addPaladio(int pal);
		void addLefkoxrisos(int lefk);
		
		Vehicles *getVehicle(); //pairnei to oxima tou simeiou
		void setVehicle(Vehicles *v); //thetei oxima sto simeio

		void removePaladius(int pal=10000); //aferei to paladio apo to simeio
		void removeIridius(int ir=10000); //aferei to iridio apo to simeio
		void removeLefkoxrisos(int lefk=10000); //aferei to lefkoxriso apo to simeio

		static position getBasePos(); //epistrefei tin thesi tis vasis
		static int getBasePosI(); //epistrefei to I tis thesis tis vasis
		static int getBasePosJ(); //epistrefei to J tis thesis tis vasis
		static void setBasePos(position pos); //thetei thesi sti vasi	

	private:
		bool base; //dilwnei an iparxei se auti ti thesi basi i oxi
		bool available; //otan einai basi i simaia
		static position base_pos;
		
		Vehicles *veh; //dixnei se oxima an iparxei panw sto PlanetSpot
};

