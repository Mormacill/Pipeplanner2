#include <math.h>

double Dichte (double T, double p)
{
return p / (287.1 * T);
}

double p_v (double zeta, double Rho, double w)
{
return zeta * (Rho / 2) * pow(w,2);
}
