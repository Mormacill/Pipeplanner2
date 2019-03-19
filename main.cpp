#include <iostream>
#include <math.h>
#include "Extras.h"
#include "Segmente.h"

using namespace std;

int main()
{

// Variablendeklarierung
int n_seg = 0;
int w_seg;
int i;
int k;

// Kalkulationsvariablen
double pv;
double Vstrom;
double arraysum = 0;

double pv1, pv2;
double Vstrom1, Vstrom2;

//Grafikvariablen
string ans;

// Head
cout << endl << endl;
cout << "\033[0;36mDruckverlustrechner für hydraulisch glatte Rohrstrecken mit dem Medium Luft  v1.0\033[0;37m" << endl << endl;
cout << "Bitte geben Sie an, aus wie vielen Segmenten Ihre Rohrstrecke besteht" << endl << endl;

cin >> n_seg;
double Druckarray[n_seg];

double Drucksammelarray[2];
double Vstromsammelarray[2];

for (k = 0; k < 2; k++)
{
cout << endl << "Bitte geben Sie den Volumenstrom (m^3/s) im Rohrsystem an" << endl << endl;
cin >> Vstrom;

for (i = 0; i < n_seg; i++)
{
cout << endl << endl << "-------------------------------------------------" << endl;
cout << endl << endl << "Wählbare Rohreinbauelemente: " << endl << endl;
cout << "Siehe Handbuch für genaue Teildefinition!" << endl << endl << endl;
cout << "1: Rohreinlauf" << endl << endl;
cout << "2: Rohrauslauf" << endl << endl;
cout << "3: plötzliche Rohrerweiterung" << endl << endl;
cout << "4: Diffusor" << endl << endl;
cout << "5: Konfusor / Düse" << endl << endl;
cout << "6: plötzliche Rohrverengung" << endl << endl;
cout << "7: Kniestück" << endl << endl;
cout << "8: Kompensatoren / Dehnungsausgleicher" << endl << endl;
cout << "9: Regler / Drosselklappe" << endl << endl;
cout << "10: gerader Rohrabschnitt" << endl << endl << endl;


// Programmstart
if (i == 0)
	{
	cout << "Bitte wählen Sie Ihr erstes Streckensegment aus!" << endl << endl;
	}
else
	{
	cout << "Bitte wählen Sie das nächste Streckensegment aus!" << endl << endl;
	}

cin >> w_seg;
cout << endl << endl;


if (w_seg == 1)
{
pv = Segment1(); //Siehe Segmente.cpp
Druckcheck(pv); //Siehe Extras.cpp
Druckarray[i] = pv;
pause(); //Siehe Extras.cpp
}

if (w_seg == 2)
{
pv = Segment2();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

if (w_seg == 3)
{
pv = Segment3();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

if (w_seg == 4)
{
pv = Segment4();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

if (w_seg == 5)
{
pv = Segment5();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

if (w_seg == 6)
{
pv = Segment6();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

if (w_seg == 7)
{
pv = Segment7();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

if (w_seg == 8)
{
pv = Segment8();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

if (w_seg == 9)
{
pv = Segment9();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

if (w_seg == 10)
{
pv = Segment10();
Druckcheck(pv);
Druckarray[i] = pv;
pause();
}

} //i-for-Schleife

arraysum = 0;

for (i = 0; i < n_seg; i++)
	{
	arraysum = arraysum + Druckarray[i];
	}
cout << endl << "Die Summe aller Druckverluste pv beträgt: " << arraysum << " Pascal" << endl << endl;

if (k == 0)
{
cout << endl << endl << "\033[0;32mZur Erstellung einer Anlagenkennlinie muss ein zweiter Rechenzyklus durchgeführt werden." << endl;
cout << "Hierzu wählen Sie bitte die gleichen Segmente in der gleichen Reihenfolge aus unter Verwendung eines anderen (kleineren) Volumenstromes und einer daraus resultierenden Strömungsgeschwindigkeit in den Segmenten.\033[0;37m" << endl << endl;
pause();
}
Drucksammelarray[k] = arraysum;
Vstromsammelarray[k] = Vstrom;

} //k-for-Schleife

pv1 = Drucksammelarray[0];
pv2 = Drucksammelarray[1];
Vstrom1 = Vstromsammelarray[0];
Vstrom2 = Vstromsammelarray[1];

cout << "Folgende Arbeitspunkte zur Erstellung einer Anlagenkennlinie wurden gesammelt:" << endl << endl;
cout << "Volumenstrom 1: " << Vstrom1 << endl;
cout << "Druckverlust 1: " << pv1 << endl << endl;
cout << "Volumenstrom 2: " << Vstrom2 << endl;
cout << "Druckverlust 2: " << pv2 << endl << endl;

cout << "Möchten Sie die Anlagenkennlinie jetzt ausgeben? (y = ja; beliebige Taste = Programm beenden)" << endl << endl;
cin >> ans;
cout << endl << endl;

if (ans == "y")
	{
	Gnuplotausgabe(pv1,pv2,Vstrom1,Vstrom2); //Siehe Extras.cpp
	}

else
	{
	return 0;
	}

} //Ende main
