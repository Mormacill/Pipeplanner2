#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H

double Dichte (double T, double p);

double p_v (double zeta, double Rho, double w);

double Re (double w, double v, double d);

double vis (double T);

double n_exp (double Rey);

long double Karman_r (long double x, long double y);

long double lambdasolver (long double Rey);

double zeta_kon (double qv);

double zeta_plv (double qv);

double zeta_knie (double theta);

double zeta_wellrohrkomp (double d);

double zeta_scharfkomp (double d);

double zeta_lyra_glatt (double d);

double zeta_lyra_falten (double d);

double zeta_lyra_well (double d);

#endif
