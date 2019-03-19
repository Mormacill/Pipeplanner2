#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int pause()
{
cout << "Zum Fortfahren bitte [Enter] drücken" << endl;
cin.get();
cin.get();
cout << endl << endl;
}

int Druckcheck(double pv)
{
if (pv <= 0)
	{
	cout << "Achtung, der resultierende Druckverlust ist kleiner oder gleich 0! Dies kann vorkommen durch die Eingabe unlogischer Daten. Bitte überprüfen Sie Ihre Eingabe und startet Sie das Programm neu!" << endl << endl;
	}
return 0;
}

int Gnuplotausgabe(double pv1, double pv2, double Vstrom1, double Vstrom2)
{
        ofstream outfile; //Schreibe Arbeitspunkte in Textfile
        outfile.open("Gnuplot_Data.dat");
        outfile << "#Volumenstrom Druckverlust" << endl << "0 0" << endl << Vstrom1 << " " << pv1 << endl << Vstrom2 << " " << pv2 << endl;
        outfile.close();

        double Volumenstromgrenze = (Vstrom1 + (Vstrom1/3));
        double Druckgrenze = (pv1 + (pv1/3));

        cout << "Eine Regression wird durch ein Polynom 2. Grades durchgeführt (a * x^2 + b * x)" << endl;
        cout << "Die ermittelten Werte für a und b werden nach der Gnuplot-Iteration angezeigt." << endl << endl;
        pause();

        string Vol1g = to_string(Volumenstromgrenze);
        string Dru1g = to_string(Druckgrenze);

        string s1 = "gnuplot ";
        string s2 = "-e \"set xlabel 'Volumenstrom [m^3/s]'\"";
        string s3 = " -e \"set ylabel 'Druckverlust [Pa]'\"";
        string s4 = " -e \"set xrange [0:" + Vol1g + "]\"";
        string s5 = " -e \"set yrange [0:" + Dru1g + "]\"";
        string s6 = " -e \"plot 'Gnuplot_Data.dat'\"";
        string s7 = " -e \"f(x) = a*x**2+b*x\"";
        string s8 = " -e \"fit f(x) 'Gnuplot_Data.dat' via a, b\"";
        string s9 = " -e \"plot f(x), 'Gnuplot_Data.dat'\"";
        string s10 = " -e \"set term png\"";
        string s11 = " -e \"set output 'Kennlinie.png'\" ";
        string s12 = " -e  \"replot\"";
        string s13 = "eog Kennlinie.png";
        string s14 = s1 + s2 +s3 + s4 + s5 + s6 + s7 + s8 + s9 + s10 + s11 + s12;
        system(s14.c_str());
        system(s13.c_str());
	return 0;
}
