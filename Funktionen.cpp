#include <iostream>
#include <math.h>

using namespace std;

double Dichte (double T, double p)
{
return p / (287.1 * T);
}

double p_v (double zeta, double Rho, double w)
{
return zeta * (Rho / 2) * pow(w,2);
}

double Re (double w, double v, double d)
{
return ((w*d)/v);
}

double vis (double T)
{
//* * * Muss noch mit 10^-7 multipliziert werden! * * *
return -1.16643853*pow(10,-13)*pow(T,5) + 3.60057235*pow(10,-10)*pow(T,4) + -5.304786536*pow(10,-7)*pow(T,3) + 0.001118914391*pow(T,2) + 0.891933997744*T + 135.2163195635;
}

double n_exp (double Rey)
{
return 3.6182 * pow(Rey,0.0611);
}

long double Karman_r (long double x, long double y)
{
//So umgestellt, dass linke Seite = 0
return (1 / pow((2 * log10(x * (sqrt(y)/2.51))),2)) - y;
}

long double lambdasolver (long double Rey) //SOLVER FÜR LAMBDA IM TURBULENTEN BEREICH NACH PRANDTL/KARMAN (hydraulisch glatt)
{
long double y_ceil = 1;
long double y_floor = 0;
long double eq = 1;
long double y = 0;
long double epsilon = 1e-10;

while (fabs(eq) > epsilon)
	{
        y = y_floor + (y_ceil - y_floor) / 2;
        cout << y << endl;
        eq = Karman_r (Rey,y);
        	if (eq < 0)
                	{
                        y_ceil = y;
                        }
                else
                	{
                        y_floor = y;
                        }
	}
return y;
}

double zeta_winkeleinlauf (double einl_delta) //Einlauf Fall 4
{
return 0.5 + 0.3 * cos(einl_delta) + 0.2 * pow(cos(einl_delta),2);
}

double zeta_Rd (double Rd) //Einlauf Fall 5 - Funktion aus polynomischer Regression von Tabellenwerten (s.S. 182 Bohl, 14. Auflage)
{
return 0.4 * pow(Rd,2) - 0.9 * Rd + 0.55;
}

double zeta_engst (double dde) //Einlauf Fall 6 - Funktion aus polynomischer Regression von Tabellenwerten (s.S. 182 Bohl, 14. Auflage)
{
return 0.0059 * pow(dde,4) - 0.1132 * pow(dde,3) + 3.4345 * pow(dde,2) -4.6504 * dde + 1.8231;
}

double zeta_ausl_rq (double n)
{
return (pow(((2 * n) + 1),3) * pow((n + 1),3)) / (4 * pow(n,4) * ((2 * n) + 3) * (n + 3));
}

double zeta_ausl_recht (double n)
{
return (pow((n + 1),3)) / (pow(n,2) * (n + 3));
}

double zeta_kreisdiff_E (double phi, double a1, double a2)
{
return 3.2 * tan(phi / 2) * pow((tan(phi / 2)),(1/4)) * pow((1 - (a1 / a2)),2);
}

double zeta_kreisdiff_R (double phi, double a1, double a2, double lambda)
{
return (lambda / (8 * sin(phi/2))) * (1 - pow((a1 / a2),2));
}

double zeta_rechtdiff_E (double phi, double a1, double a2)
{
return 4 * tan(phi / 2) * pow((tan(phi / 2)),(1/4)) * pow((1 - (a1 / a2)),2);
}

double zeta_rechtdiff_R (double phi, double a1, double a2, double lambda)
{
return (lambda / (16 * sin(phi/2))) * (1 - pow((a1 / a2),2));
}

double zeta_flachdiff_E (double phi, double a1, double a2)
{
return 3.2 * tan(phi / 2) * pow((tan(phi / 2)),(1/4)) * pow((1 - (a1 / a2)),2);
}

double zeta_flachdiff_R (double phi, double a1, double a2, double lambda, double h1, double b)
{
return (lambda / (4 * sin(phi/2))) * ((h1 / b) * (1 - (a1 / a2)) + 0.5 * (1 - pow((a1 / a2),2)));
}

double zeta_kon (double qv)
{
return 0.3358 * pow(qv,4) - 1.1084 * pow(qv,3) + 0.9916 * pow(qv,2) - 0.3351 * qv + 0.116;
}

double zeta_plv (double qv)
{
return -0.4429 * qv + 0.4429;
}

double zeta_knie (double theta)
{
return 0.0001 * pow(theta,2) - 0.0008 * theta + 0.0016;
}

double zeta_wellrohrkomp (double d)
{
return -29.618 * pow(d,4) + 10.176 * pow(d,3) + 11.74 * pow(d,2) - 3.8326 * d + 1.8605;
}

double zeta_scharfkomp (double d)
{
return 2 * d + 1.9;
}

double zeta_lyra_glatt (double d)
{
return 2 * d + 1.6;
}

double zeta_lyra_falten (double d)
{
return -104.51 * pow(d,4) + 140.29 * pow(d,3) - 64.366 * pow(d,2) + 14.79 * d + 1.1909;
}

double zeta_lyra_well (double d)
{
return -36.102 * pow(d,4) + 39.869 * pow(d,3) - 15.802 * pow(d,2) + 7.0576 * d + 2.6917;
}
