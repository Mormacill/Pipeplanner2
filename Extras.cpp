#include <iostream>

using namespace std;

int pause()
{
cout << "Zum Fortfahren bitte [Enter] drücken" << endl;
cin.get();
cout << endl << endl;
}

int Druckcheck(pv)
{
if (pv <= 0)
	{
	cout << "Achtung, der resultierende Druckverlust ist kleiner oder gleich 0! Dies kann vorkommen durch die Eingabe unlogischer Daten. Bitte überprüfen Sie Ihre eingabe!" << endl << endl;
	}
return 0;
}
