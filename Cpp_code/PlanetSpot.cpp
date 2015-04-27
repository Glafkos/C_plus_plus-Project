#include "PlanetSpot.h"

position PlanetSpot::base_pos = position(0,0);


PlanetSpot::PlanetSpot(int a, int b, bool risk_fl, float acc_risk, int cont_lefk, int cont_irid, int cont_pall)
{
	position thesi;
	thesi.i = a;
	thesi.j = b;
	
	setAvailable();

	pos = thesi;
	risk_flag = risk_fl;
	access_risk = acc_risk;
	content_lefkoxrisos = cont_lefk;
	content_iridio = cont_irid;
	content_palladio = cont_pall;

	base = false;

	veh = 0; //vazw to dixti tou oximatos na mi dixnei pouthena

//	cout << "Planet spot with: " << endl;
//	printInfo();
//	cout << "CREATED \n"; 
}

PlanetSpot::~PlanetSpot()
{
	cout << "-------------------------------------------------------------- \n";
	cout << "PlanetSpot with: \n";
	printInfo();
	cout << "DELETED \n";
	cout << "-------------------------------------------------------------- \n";
}

void PlanetSpot::printInfo()
{
	cout << "This PlanetSpot has: \n";
	cout << "Position: " << pos.i << ", " << pos.j << endl;
	cout << "Palladium 's content: " << content_palladio << endl;
	cout << "Platinum 's content: " << content_lefkoxrisos << endl;
	cout << "Iridium 's content: " << content_iridio << endl;
	cout << "Available: " << getAvailable() << endl;
	cout << "Has ";
	if (access_risk < HIGH_ACCESS_RISK)
	{
		cout << "no ";
	}
	cout << "access risk (" << access_risk << ") \n";
}

/*sinartisis opou epistrefei tin epikindinotita prosvasis*/
float PlanetSpot::getAccessRisk()
{
	return access_risk;
}

void PlanetSpot::setRandomContents()
{ 
	int pal=0, irid=0, lefk=0;

	pal = rand() % 101; //random [0, 100]
	if (101 - pal != 0)
	{
		irid = rand() % (101 - pal); //random [0,100]
	}
	if (101 - (pal + irid) != 0)
	{
		lefk = rand() % ( 101 - (pal + irid) );
	}
	content_palladio = pal;
	content_lefkoxrisos = lefk;
	content_iridio = irid;
}

int PlanetSpot::getSumContent()
{
	
	return (content_iridio + content_lefkoxrisos + content_palladio);
}

bool PlanetSpot::hasRiskFlag()
{
	return risk_flag;
}

void PlanetSpot::setRiskFlag(bool flag)
{
	risk_flag = flag;
}

void PlanetSpot::setRandomAccessRisk()
{
	int rnd;
	rnd = rand() % 100; //rnd [0, 99]
	access_risk = rnd * 0.01;
}

void PlanetSpot::setAvailable(bool av)
{
	available = av;
}

bool PlanetSpot::getAvailable()
{
	return available;
}

void PlanetSpot::setBase(bool bs)
{
	base = bs;
	if(base == true)
	{
		setAvailable(false);
		content_iridio = 0;
		content_lefkoxrisos = 0;
		content_palladio = 0;
		base_pos.i = pos.i;
		base_pos.j = pos.j;
		access_risk = 0;
		cout << "Base putted at : (" << pos.i << ", " << pos.j << ") " "\n";
	}
}

bool PlanetSpot::getBase()
{
	return base;
}

int PlanetSpot::getIridius()
{
	return content_iridio;
}

int PlanetSpot::getLefkoxrisos()
{
	return content_lefkoxrisos;
}

int PlanetSpot::getPaladio()
{
	return content_palladio;
}

position PlanetSpot::getBasePos()
{
	return base_pos;
}

void PlanetSpot::setBasePos(position pos)
{
	base_pos = pos;
}

int PlanetSpot::getBasePosI()
{
	return base_pos.i;
}

int PlanetSpot::getBasePosJ()
{
	return base_pos.j;
}

void PlanetSpot::addIridio(int ir)
{
	content_iridio += ir;
}

void PlanetSpot::addLefkoxrisos(int lefk)
{
	content_lefkoxrisos += lefk;
}

void PlanetSpot::addPaladio(int pal)
{
	content_palladio += pal;
}

void PlanetSpot::setVehicle(Vehicles *v)
{
	veh = v;
}

Vehicles* PlanetSpot::getVehicle()
{
	return veh;
}

void PlanetSpot::removeIridius(int ir)
{
	if( ir >= content_iridio )
	{
		content_iridio = 0;
	}
	else
	{
		content_iridio -= ir;
	}
}

void PlanetSpot::removeLefkoxrisos(int lefk)
{
	if ( lefk >= content_lefkoxrisos )
	{
		content_lefkoxrisos = 0;
	}
	else
	{
		content_lefkoxrisos -= lefk;
	}
}

void PlanetSpot::removePaladius(int pal)
{
	if ( pal >= content_palladio )
	{
		content_palladio = 0;
	}
	else
	{
		content_palladio -= pal;
	}
}

void PlanetSpot::setPaladio(int pal)
{
	content_palladio = pal;
}

void PlanetSpot::setLefkoxisos(int lefk)
{
	content_lefkoxrisos = lefk;
}

void PlanetSpot::setIridio(int ir)
{
	content_iridio = ir;
}

void PlanetSpot::setAccessRisk(float accRisk)
{
	access_risk = accRisk;
}