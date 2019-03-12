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
double T;
double p;
double Rho;
double w;
double pv;
double Rey;
double kin_vis;
double d;
double n;
double d_duse;
double d1, d2;
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
	cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
	cin >> T;
	T = T + 273.15; //Umrechnung Celsius zu Kelvin
	cout << endl << endl << "Bitte geben Sie den Druck (Bar) des Strömungsmediums ein" << endl << endl;
	cin >> p;
	p = p * 100000; //Umrechnung Bar zu Pascal
 	Rho = Dichte(T,p);
	cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Einlauf an" << endl << endl;
	cin >> w;
	pv = p_v (zeta, Rho, w);
	cout << endl << endl << "Der Druckverlust infolge von Reibung für den Einlauf beträgt: " << pv << " Pascal" << endl << endl;
	}

if (w_seg == 2)
	{
	cout << "*Segment Rohrauslauf*" << endl << endl;
        cout << "Bitte schlagen Sie im Handbuch das entsprechende Kapitel auf!" << endl << endl;
	cout << "Welcher Rohrauslauf liegt vor?" << endl << endl << endl;
        cout << "1: Fall 1" << endl;
        cout << "2: Fall 2" << endl;
        cout << "3: Fall 3" << endl;
        cout << "4: Fall 4" << endl;
 //     cout << "5: Fall 5" << endl;
	cin >> w_fall;

	if (w_fall == 1)
		{
		zeta = 1;
		cout << endl << endl << "Für die Rechnung wird ein Zeta-Wert von " << zeta << " verwendet" << endl << endl;
		}

	if (w_fall == 2)
		{
		cout << endl << endl << "Liegt ein runder oder quadratischer (1) oder ein rechteckiger (2) Strömungquerschnitt vor?" << endl << endl;
		cin >> w_individual;
		if (w_individual == 1)
                        {
                        zeta = 2;
                        }
                if (w_individual == 2)
                        {
                        zeta = 1.55;
                        }
                cout << endl << endl << "Für die Rechnung wird ein Zeta-Wert von " << zeta << " verwendet" << endl << endl;
		}

	if (w_fall == 3)
		{
		cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein (Gültigkeitsbereich -40 - 500°C)" << endl << endl;
        	cin >> T;
        	kin_vis = vis(T);
		kin_vis = kin_vis * pow(10,-7);
		cout << endl << endl << "Bitte geben sie die Strömungsgeschwindigkeit (m/s) im Auslauf an" << endl << endl;
		cin >> w;
		cout << endl << endl << "Bitte geben Sie den (hydraulischen) Durchmesser (m) des Rohres an" << endl << endl;
		cin >> d;
		Rey = Re(w,kin_vis,d);
		n = n_exp(Rey);
		cout << endl << endl << "Liegt ein runder oder quadratischer (1) oder ein rechteckiger (2) Strömungquerschnitt vor?" << endl << endl;
		cin >> w_individual;
                if (w_individual == 1)
                        {
                        zeta = (pow(((2 * n) + 1),3) * pow((n + 1),3)) / (4 * pow(n,4) * ((2 * n) + 3) * (n + 3));
                        }
                if (w_individual == 2)
                        {
                        zeta = (pow((n + 1),3)) / (pow(n,2) * (n + 3));
                        }
		cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
		}


	if (w_fall == 4)
		{
		cout << "Bitte geben Sie den Rohrdurchmesser (m) an" << endl << endl;
		cin >> d;
		cout << endl << endl << "Bitte geben Sie den Düsendurchmesser (m) an" << endl << endl;
		cin >> d_duse;
		zeta = pow((d / d_duse),4);
		cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
		}

	cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
        cin >> T;
        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Druck (Bar) des Strömungsmediums ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Einlauf an" << endl << endl;
        cin >> w;
        pv = p_v (zeta, Rho, w);
        cout << endl << endl << "Der Druckverlust infolge von Reibung für den Einlauf beträgt: " << pv << " Pascal" << endl << endl;

/*	if (w_fall == 5)
		{

		}	*/
	}

if (w_seg == 3)
        {
        cout << "*Segment plötzliche Rohrerweiterung*" << endl << endl;
        cout << "Bitte schlagen Sie im Handbuch das entsprechende Kapitel auf!" << endl << endl;
	cout << "Möchte Sie die Berechnung des Zeta-Wertes auf den Eintritts- (1) oder den Austrittsquerschnitt (2) beziehen?" << endl << endl;
	cin >> w_individual;
        	if (w_individual == 1)
        		{
			cout << "Bitte geben Sie den Eintrittsdurchmesser d1 (m) an" << endl << endl;
			cin >> d1;
			cout << endl << endl << "Bitte geben Sie den Austrittsdurchmesser d2 (m) an" << endl << endl;
                        cin >> d2;
                        zeta = pow((1 - pow((d1 / d2),2)),2);
			cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
        		cin >> T;
        		T = T + 273.15; //Umrechnung Celsius zu Kelvin
       			cout << endl << endl << "Bitte geben Sie den Druck (Bar) des Strömungsmediums ein" << endl << endl;
        		cin >> p;
        		p = p * 100000; //Umrechnung Bar zu Pascal
        		Rho = Dichte(T,p);
        		cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Eintrittsquerschnitt an" << endl << endl;
        		cin >> w;
        		pv = p_v (zeta, Rho, w);
        		cout << endl << endl << "Der Druckverlust infolge von Reibung für die auf den Eintrittsquerschnitt bezogene plötzliche Rohrerweiterung beträgt: " << pv << " Pascal" << endl << endl;
                 	}
                if (w_individual == 2)
                        {
			cout << "Bitte geben Sie den Eintrittsdurchmesser d1 (m) an" << endl << endl;
                        cin >> d1;
                        cout << endl << endl << "Bitte geben Sie den Austrittsdurchmesser d2 (m) an" << endl << endl;
                        cin >> d2;
                        zeta = pow((pow((d2 / d1),2) - 1),2);
			cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
                        cin >> T;
                        T = T + 273.15; //Umrechnung Celsius zu Kelvin
                        cout << endl << endl << "Bitte geben Sie den Druck (Bar) des Strömungsmediums ein" << endl << endl;
                        cin >> p;
                        p = p * 100000; //Umrechnung Bar zu Pascal
                        Rho = Dichte(T,p);
                        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Austrittsquerschnitt an" << endl << endl;
                        cin >> w;
                        pv = p_v (zeta, Rho, w);
                        cout << endl << endl << "Der Druckverlust infolge von Reibung für die auf den Austrittsquerschnitt bezogene plötzliche Rohrerweiterung beträgt: " << pv << " Pascal" << endl << endl;
                        }
	}

if (w_seg == 4)
        {
        cout << "*Segment Diffusor*" << endl << endl;
        cout << "Bitte schlagen Sie im Handbuch das entsprechende Kapitel auf!" << endl << endl;
	}
















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
