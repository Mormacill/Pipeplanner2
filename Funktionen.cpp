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

long double lambdasolver (long double Rey) //SOLVER FÜR LAMBDA IM TURBULENTEN BEREICH NACH PRANDTL/KARMAN
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
