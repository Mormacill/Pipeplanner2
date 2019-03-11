#include <iostream>
#include <math.h>
#include "Funktionen.h"

using namespace std;

int main()
{

// Variablendeklarierung
int n_seg = 0;
int w_seg;
int w_fall;
int w_individual;

// Kalkulationsvariablen
double zeta;
double einl_delta;
double Rd;
double dde;

// Head
cout << "Druckverlustrechner für hydraulisch glatte Rohrstrecken mit dem Medium Luft  v1.0" << endl << endl;
cout << "Bitte geben Sie an, aus wie vielen Segmenten Ihre Rohrstrecke besteht" << endl << endl;

cout << endl;

cin >> n_seg;
double Druckarray[n_seg];

cout << endl;

cout << "Wählbare Rohreinbauelemente: " << endl << endl;
cout << "Siehe Handbuch für genaue Teildefinition!" << endl << endl << endl;
cout << "1: Rohreinlauf" << endl << endl;
cout << "2: Rohrauslauf" << endl << endl;
cout << "3: plötzliche Rohrerweiterung" << endl << endl;
cout << "4: Diffusor" << endl << endl;
cout << "5: Konfusor" << endl << endl;
cout << "6: plötzliche Rohrverengung" << endl << endl;
cout << "7: Düse" << endl << endl;
cout << "8: Krümmer" << endl << endl;
cout << "9: Kniestück" << endl << endl;
cout << "10: Dehnungsausgleicher" << endl << endl;
cout << "11: Regelarmatur" << endl << endl;
cout << "12: gerader Rohrabschnitt" << endl << endl << endl;


// Programmstart
cout << "Bitte wählen sie Ihr erstes Streckensegment aus!" << endl << endl;

cin >> w_seg;

if (w_seg == 1)
	{
	cout << "*Segment Rohreinlauf*" << endl << endl;
	cout << "Bitte schlagen Sie im Handbuch das entsprechende Kapitel auf!" << endl << endl;
	cout << "Welcher Rohreinlauf liegt vor?" << endl << endl << endl;
	cout << "1: Fall 1" << endl;
	cout << "2: Fall 2" << endl;
	cout << "3: Fall 3" << endl;
	cout << "4: Fall 4" << endl;
	cout << "5: Fall 5" << endl;
	cout << "6: Fall 6" << endl << endl;
	cin >> w_fall;

	if (w_fall == 1)
		{
		cout << endl << endl << "Ist der Einlauf scharfkantig (1) oder gebrochen (2)?" << endl << endl;
		cin >> w_individual;
		if (w_individual == 1)
			{
			zeta = 0.5;
			}
		if (w_individual == 2)
			{
			zeta = 0.25;
			}
		cout << "Für die Rechnung wird ein Zeta-Wert von " << zeta << " verwendet" << endl << endl;
		}

	if (w_fall == 2 || w_fall == 3)
		{
		cout << endl << endl << "Ist der Einlauf scharfkantig (1) oder gebrochen (2)?" << endl << endl;
		cin >> w_individual;
                if (w_individual == 1)
                        {
                        zeta = 3;
                        }
                if (w_individual == 2)
                        {
                        zeta = 0.8;
                        }
		cout << "Für die Rechnung wird ein Zeta-Wert von " << zeta << " verwendet" << endl << endl;
		}

	if (w_fall == 4)
		{
		cout << endl << endl << "Bitte geben Sie den Knickwinkel delta (in Grad) des Einlaufs an" << endl << endl;
		cin >> einl_delta;
		einl_delta = einl_delta * M_PI/180; //Umrechnung von Grad in Radiant
		zeta = 0.5 + 0.3 * cos(einl_delta) + 0.2 * pow(cos(einl_delta),2);
		cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
		}

	if (w_fall == 5)
		{
		cout << endl << endl << "Bitte geben Sie das Verhältniss vom Einlaufradius zum Rohrdurchmesser R/d an" << endl << endl;
		cin >> Rd;
		if (Rd <= 0.5)
			{
			zeta = 0.2;
			}
		else
			{
			zeta = 0.4 * pow(Rd,2) - 0.9 * Rd + 0.55; //Funktion aus polynomischer Regression von Tabellenwerten (s.S. 182 Bohl, 14. Auflage)
			}
		cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
		}

	if (w_fall == 6)
		{
		cout << endl << endl << "Bitte geben Sie das quadrierte Verhältnis vom Rohrdurchmesser zum Einlaufdurchmesser (d/de)^2 an" << endl << endl;
		cin >> dde;
		zeta = 0.0059 * pow(dde,4) - 0.1132 * pow(dde,3) + 3.4345 * pow(dde,2) -4.6504 * dde + 1.8231;  //Funktion aus polynomischer Regression von Tabellenwerten (s.S. 182 Bohl, 14. Auflage)
		cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
		}
	}

/*if (w_seg == 2)
	{

	}
*/
















/*int i;

for (i=0; i<n_seg; i++)
{
  Druckarray[i] = 2;
}

for (i=0; i<n_seg; i++)
{
cout << Druckarray[i] << endl;
}
*/



}
