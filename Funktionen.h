#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H

double Dichte (double T, double p);

double p_v (double zeta, double Rho, double w);

double Re (double w, double v, double d);

double vis (double T);

double n_exp (double Rey);

long double Karman_r (long double x, long double y);

long double lambdasolver (long double Rey);

#endif
