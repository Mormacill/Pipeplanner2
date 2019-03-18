#include <iostream>
#include <math.h>
#include "Funktionen.h"

using namespace std;

// Variablendeklarierung
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
long double lambda;
double a1, a2;
double phi;
double zeta_E, zeta_R;
double h1;
double b;
double theta;
double n_wellen;
double a;
double w1, w2;
double l;




double Segment1()
{
        cout << "*Segment Rohreinlauf*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
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
                cout << endl << endl << "Für die Rechnung wird ein Zeta-Wert von " << zeta << " verwendet" << endl << endl;
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
                cout << endl << endl << "Für die Rechnung wird ein Zeta-Wert von " << zeta << " verwendet" << endl << endl;
                }

        if (w_fall == 4)
                {
                cout << endl << endl << "Bitte geben Sie den Knickwinkel delta (in Grad) des Einlaufs an" << endl << endl;
                cin >> einl_delta;
                einl_delta = einl_delta * M_PI/180; //Umrechnung von Grad in Radiant
                zeta = zeta_winkeleinlauf(einl_delta);
                cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
                }

        if (w_fall == 5)
                {
                cout << endl << endl << "Bitte geben Sie das Verhältnis vom Einlaufradius zum Rohrdurchmesser R/d an" << endl << endl;
                cin >> Rd;
                if (Rd <= 0.5)
                        {
                        zeta = 0.2;
                        }
                else
                        {
                        zeta = zeta_Rd(Rd);
                        }
                cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
                }

	if (w_fall == 6)
                {
                cout << endl << endl << "Bitte geben Sie das quadrierte Verhältnis vom Rohrdurchmesser zum Einlaufdurchmesser (d/de)^2 an" << endl << endl;
                cin >> dde;
                zeta = zeta_engst(dde);
                cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
                }
        cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
        cin >> T;
        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Einlauf an" << endl << endl;
        cin >> w;
        pv = p_v (zeta, Rho, w);
        cout << endl << endl << "Der Druckverlust infolge von Reibung für den Einlauf beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}

double Segment2()
{
        cout << "*Segment Rohrauslauf*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Welcher Rohrauslauf liegt vor?" << endl << endl << endl;
        cout << "1: Fall 1" << endl;
        cout << "2: Fall 2" << endl;
        cout << "3: Fall 3" << endl;
        cout << "4: Fall 4" << endl;
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
                cout << endl << endl << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein (Gültigkeitsbereich -40 - 500°C)" << endl << endl;
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
                        zeta = zeta_ausl_rq(n);
                        }
                if (w_individual == 2)
                        {
                        zeta = zeta_ausl_recht(n);
                        }
                cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
                }

	if (w_fall == 4)
                {
                cout << endl << endl << "Bitte geben Sie den Rohrdurchmesser (m) an" << endl << endl;
                cin >> d;
                cout << endl << endl << "Bitte geben Sie den Düsendurchmesser (m) an" << endl << endl;
                cin >> d_duse;
                zeta = pow((d / d_duse),4);
                cout << endl << endl << "Für die Rechnung wurde ein Zeta-Wert von " << zeta << " errechnet" << endl << endl;
                }

        cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
        cin >> T;
        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Einlauf an" << endl << endl;
        cin >> w;
        pv = p_v (zeta, Rho, w);
        cout << endl << endl << "Der Druckverlust infolge von Reibung für den Einlauf beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}

double Segment3()
{
	cout << "*Segment plötzliche Rohrerweiterung*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Möchten Sie die Berechnung des Zeta-Wertes auf den Eintritts- (1) oder den Austrittsquerschnitt (2) beziehen?" << endl << endl;
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
                        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
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
                        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
                        cin >> p;
                        p = p * 100000; //Umrechnung Bar zu Pascal
                        Rho = Dichte(T,p);
                        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Austrittsquerschnitt an" << endl << endl;
                        cin >> w;
                        pv = p_v (zeta, Rho, w);
                        cout << endl << endl << "Der Druckverlust infolge von Reibung für die auf den Austrittsquerschnitt bezogene plötzliche Rohrerweiterung beträgt: " << pv << " Pascal" << endl << endl;
                        }
	return pv;
}

double Segment4()
{
	cout << "*Segment Diffusor*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein (Gültigkeitsbereich -40 - 500°C)" << endl << endl;
        cin >> T;
        kin_vis = vis(T);
        kin_vis = kin_vis * pow(10,-7);
        cout << endl << endl << "Bitte geben sie die Strömungsgeschwindigkeit (m/s) im Einlauf an" << endl << endl;
        cin >> w;
        cout << endl << endl << "Bitte geben Sie den (hydraulischen) Durchmesser (m) des Einlaufes an" << endl << endl;
        cin >> d1;
        cout << endl << endl;
        Rey = Re(w,kin_vis,d1);

        if (Rey < 2300)
                {
                lambda = 64 / Rey; //laminare Strömung
                }
        else
                {
                lambda = lambdasolver(Rey);
                cout << endl << endl << "Der Rohrreibungsbeiwert Lambda wurde iterativ ermittelt und liegt bei " << lambda << endl << endl;
                }
        a1 = (M_PI / 4) * pow(d1,2);
        cout << endl << endl << "Bitte geben Sie den (hydraulischen) Durchmesser (m) des Austritts an" << endl << endl;
        cin >> d2;
        a2 = (M_PI / 4) * pow(d2,2);
        cout << endl << endl << "Liegt ein Kreisdiffusor (1), ein Rechteckdiffusor (2) oder ein Flachdiffusor (3) vor?" << endl << endl;
        cin >> w_fall;
        if (w_fall == 1)
                {
                cout << endl << endl << "Bitte geben Sie den Öffnungswinkel des Kreisdiffusors an (Gültigkeitsbereich 0 - 40°)" << endl << endl;
                cin >> phi;
                zeta_E = zeta_kreisdiff_E(phi,a1,a2);
                zeta_R = zeta_kreisdiff_R(phi,a1,a2,lambda);
                zeta = zeta_E + zeta_R;
                }
	 if (w_fall == 2)
                {
                cout << endl << endl << "Bitte geben Sie den Öffnungswinkel des Rechteckdiffusors an (Gültigkeitsbereich 0 - 25°)" << endl << endl;
                cin >> phi;
                zeta_E = zeta_rechtdiff_E(phi,a1,a2);
                zeta_R = zeta_rechtdiff_R(phi,a1,a2,lambda);
                zeta = zeta_E + zeta_R;
                }
        if (w_fall == 3)
                {
                cout << endl << endl << "Bitte geben Sie den Öffnungswinkel des Flachdiffusors an (Gültigkeitsbereich 0 - 40°)" << endl << endl;
                cin >> phi;
                cout << endl << endl << "Bitte geben Sie die Diffusorhöhe (m) am Eintritt an" << endl << endl;
                cin >> h1;
                cout << endl << endl << "Bitte geben Sie die Diffusorbreite (m) an" << endl << endl;
                cin >> b;
                zeta_E = zeta_flachdiff_E(phi,a1,a2);
                zeta_R = zeta_flachdiff_R(phi,a1,a2,lambda,h1,b);
                zeta = zeta_E + zeta_R;
                }

        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums am Diffusoreintritt ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        pv = p_v (zeta, Rho, w);
        cout << endl << endl << "Der Druckverlust infolge von Reibung für den Diffusor beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}

double Segment5()
{
	cout << "*Segment Konfusor / Düse*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Bitte geben Sie den Eintrittsdurchmesser (m) des Konfusors ein" << endl << endl;
        cin >> d1;
        a1 = (M_PI / 4) * pow(d1,2);
        cout << endl << endl << "Bitte geben Sie den Austrittssdurchmesser (m) des Konfusors ein" << endl << endl;
        cin >> d2;
        a2 = (M_PI / 4) * pow(d2,2);
        zeta = zeta_kon((a2 / a1));

        cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
        cin >> T;
        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) am Konfusoraustritt an" << endl << endl;
        cin >> w;
        pv = p_v (zeta, Rho, w);
        cout << endl << endl << "Der Druckverlust infolge von Reibung für den Konfusor / Düse beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}

double Segment6()
{
	cout << "*Segment plötzliche Rohrverengung*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Bitte geben Sie den Eintrittsdurchmesser (m) des Konfusors ein" << endl << endl;
        cin >> d1;
        a1 = (M_PI / 4) * pow(d1,2);
        cout << endl << endl << "Bitte geben Sie den Austrittssdurchmesser (m) des Konfusors ein" << endl << endl;
        cin >> d2;
        a2 = (M_PI / 4) * pow(d2,2);
        zeta = zeta_plv((a2 / a1));

        cout << endl << endl << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
        cin >> T;
        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) am Austritt an" << endl << endl;
        cin >> w;
        pv = p_v (zeta, Rho, w);
        cout << endl << endl << "Der Druckverlust infolge von Reibung für die Rohrverengung beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}

double Segment7()
{
	cout << "*Segment Kniestück*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Bitte geben Sie den Umlenkwinkel (Grad) des Kniestückes an (Gültigkeitsbereich 0 - 90°)" << endl << endl;
        cin >> theta;
        zeta = zeta_knie(theta);

        cout << endl << endl << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
        cin >> T;
        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Kniestück an" << endl << endl;
        cin >> w;
        pv = p_v (zeta, Rho, w);
        cout << endl << endl << "Der Druckverlust infolge von Reibung für das Kniestück beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}

double Segment8()
{
	cout << "*Segment Kompensator / Dehnungsausgleicher*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Bitte geben Sie den Kompensatortyp an" << endl << endl;
        cout << "1: Stopfbuchskompensator" << endl;
        cout << "2: Wellrohrkompensator" << endl;
        cout << "3: U-Bogen mit Krümmern" << endl;
        cout << "4: scharfkantiger U-Bogen" << endl;
        cout << "5: Lyrabogen" << endl << endl;
        cin >> w_fall;
        if (w_fall == 1)
                {
                zeta = 0.2;
                }
        if (w_fall == 2)
                {
                cout << endl << endl << "Bitte geben Sie den Durchmesser (m) des Wellrohrkompensators ein" << endl << endl;
                cin >> d;
                zeta = zeta_wellrohrkomp(d);
                cout << endl << endl << "Wie viele Wellen hat der Kompensator?" << endl << endl;
                cin >> n_wellen;
                zeta = zeta + (0.2 * (n_wellen - 1));
                }
	if (w_fall == 3)
                {
                cout << endl << endl << "Bitte geben Sie die Länge der Zwischengeraden a (m) an" << endl << endl;
                cin >> a;
                cout << endl << endl << "Bitte geben Sie den Rohrdurchmesser (m) an" << endl << endl;
                cin >> d;
                if ((a / d) <= 1)
                        {
                        zeta = 0.33;
                        }
                else
                        {
                        zeta = 0.21;
                        }
                }
        if (w_fall == 4)
                {
                cout << endl << endl << "Bitte geben Sie den Durchmesser (m) des scharfkantigen U-Bogens an" << endl << endl;
                cin >> d;
                zeta = zeta_scharfkomp(d);
                }
	 if (w_fall == 5)
                {
                cout << endl << endl << "Um welche Art von Lyra-Bogen handelt es sich?" << endl << endl;
                cout << "1: Glattrohr" << endl;
                cout << "2: Faltenrohr" << endl;
                cout << "3: Wellrohr" << endl << endl;
                cin >> w_individual;
                if (w_individual == 1)
                        {
                        cout << endl << endl << "ACHTUNG: Der ermittelte Zeta-Wert gilt nur für R0 / d = 6 und r / d = 5!" << endl << endl;
                        cout << endl << endl << "Bitte geben Sie den Durchmesser (m) des Glattrohrs an" << endl << endl;
                        cin >> d;
                        zeta = zeta_lyra_glatt(d);
                        }
                if (w_individual == 2)
                        {
                        cout << endl << endl << "ACHTUNG: Der ermittelte Zeta-Wert gilt nur für R0 / d = 6 und r / d = 6!" << endl << endl;
                        cout << endl << endl << "Bitte geben Sie den Durchmesser (m) des Faltenrohrs an" << endl << endl;
                        cin >> d;
                        zeta = zeta_lyra_falten(d);
                        }
                if (w_individual == 3)
                        {
                        cout << endl << endl << "ACHTUNG: Der ermittelte Zeta-Wert gilt nur für R0 / d = 5 und r / d = 3!" << endl << endl;
                        cout << endl << endl << "Bitte geben Sie den Durchmesser (m) des Wellrohrs an" << endl << endl;
                        cin >> d;
                        zeta = zeta_lyra_well(d);
                        }
		}
                cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
                cin >> T;
                T = T + 273.15; //Umrechnung Celsius zu Kelvin
                cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
                cin >> p;
                p = p * 100000; //Umrechnung Bar zu Pascal
                Rho = Dichte(T,p);
                cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) im Kompensator an" << endl << endl;
                cin >> w;
                pv = p_v (zeta, Rho, w);
                cout << endl << endl << "Der Druckverlust infolge von Reibung für den gewählten Kompensator beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}

double Segment9()
{
	cout << "*Segment Regler / Drosselklappe*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein" << endl << endl;
        cin >> T;
        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        cout << endl << endl << "Bitte geben Sie die Strömungsgeschwindigkeit (m/s) am Eintritt an" << endl << endl;
        cin >> w1;
        cout << endl << endl << "Bitte geben Sie den Durchmesser (m) am Eintritt an" << endl << endl;
        cin >> d1;
        a1 = (M_PI / 4) * pow(d1,2);
        cout << endl << endl << "Bitte geben Sie bei gewünschter Stellung der Drosselklappe die versperrte Fläche an" << endl << endl;
        cin >> a2;
        a2 = a1 - a2;
        w2 = w1 * (a1 / a2);
        pv = (Rho / 2) * pow((w1 - w2),2);
        cout << endl << endl << "Der Druckverlust infolge von Versperrung für das Drosselelement beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}

double Segment10()
{
        cout << "*Segment gerades Rohr*" << endl << endl;
        cout << "\033[0;31mBitte schlagen Sie im Handbuch das entsprechende Kapitel auf!\033[0;37m" << endl << endl;
        cout << "Bitte geben Sie die Temperatur (Celsius) des Strömungsmediums ein (Gültigkeitsbereich -40 - 500°C)" << endl << endl;
        cin >> T;
        kin_vis = vis(T);
        kin_vis = kin_vis * pow(10,-7);
        cout << endl << endl << "Bitte geben sie die Strömungsgeschwindigkeit (m/s) im Rohr an" << endl << endl;
        cin >> w;
        cout << endl << endl << "Bitte geben Sie den (hydraulischen) Durchmesser (m) des Rohres an" << endl << endl;
        cin >> d;
        cout << endl << endl;
        Rey = Re(w,kin_vis,d);
        if (Rey < 2300)
                {
                lambda = 64 / Rey; //laminare Strömung
                }
        else
                {
                lambda = lambdasolver(Rey);
                cout << endl << endl << "Der Rohrreibungsbeiwert Lambda wurde iterativ ermittelt und liegt bei " << lambda << endl << endl;
                }
        cout << endl << endl << "Bitte geben Sie die Länge (m) des Rohrabschnittes an" << endl << endl;
        cin >> l;
        zeta = lambda * (l / d);
        T = T + 273.15; //Umrechnung Celsius zu Kelvin
        cout << endl << endl << "Bitte geben Sie den Gesamtdruck (Bar) des Strömungsmediums ein" << endl << endl;
        cin >> p;
        p = p * 100000; //Umrechnung Bar zu Pascal
        Rho = Dichte(T,p);
        pv = p_v (zeta, Rho, w);
        cout << endl << endl << "Der Druckverlust infolge von Reibung für den geraden Rohrabschnitt beträgt: " << pv << " Pascal" << endl << endl;
	return pv;
}
