#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H

double Dichte (double T, double p);

double p_v (double zeta, double Rho, double w);

double Re (double w, double v, double d);

double vis (double T);

double n_exp (double Rey);

long double Karman_r (long double x, long double y);

long double lambdasolver (long double Rey);

double zeta_winkeleinlauf (double einl_delta);

double zeta_Rd (double Rd);

double zeta_engst (double dde);

double zeta_ausl_rq (double n);

double zeta_ausl_recht (double n);

double zeta_kreisdiff_E (double phi, double a1, double a2);

double zeta_kreisdiff_R (double phi, double a1, double a2, double lambda);

double zeta_rechtdiff_E (double phi, double a1, double a2);

double zeta_rechtdiff_R (double phi, double a1, double a2, double lambda);

double zeta_flachdiff_E (double phi, double a1, double a2);

double zeta_flachdiff_R (double phi, double a1, double a2, double lambda, double h1, double b);

double zeta_kon (double qv);

double zeta_plv (double qv);

double zeta_knie (double theta);

double zeta_wellrohrkomp (double d);

double zeta_scharfkomp (double d);

double zeta_lyra_glatt (double d);

double zeta_lyra_falten (double d);

double zeta_lyra_well (double d);

#endif
