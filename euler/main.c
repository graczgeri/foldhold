//racz gergely
//goz1np
//euler

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double Mf=5.9736e+24;
    double Mh=7.349e+22;
    double apog=405500000;
    double v_apog=964;
    double peri=363300000;
    double v_peri=1076;
    double G=6.67384e-11;

    int step=3600*24*30;
    double h=1200.0;

    double* x=(double*)calloc(step, sizeof(double));
    double* y=(double*)calloc(step, sizeof(double));

    x[0]=0;
    y[0]=apog;

    euler(x,y,h,v_apog,0,step);
    printf("az euler.dat tartalmazza a koordinatakat");
    return 0;

}