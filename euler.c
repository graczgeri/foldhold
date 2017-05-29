//racz gergely
//goz1np
//euler

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void euler(double* x, double* y, double h, double vx_1, double vy_1, int step)
{
    double Mf=5.9736e+24;
    double Mh=7.349e+22;
    double apog=405500000;
    double v_apog=964;
    double peri=363300000;
    double v_peri=1076;
    double G=6.67384e-11;

    double t=0;
    double fx, fy, vx_2, vy_2;
    int i=0;

    FILE*f;
    f=fopen("euler.dat", "w");

    //printf("x: \t y: \n");

    while (t<step)
    {
        fx=(-G*Mf*Mh*x[i])/pow(sqrt(pow(x[i],2)+pow(y[i],2)),3);
        fy=(-G*Mf*Mh*y[i])/pow(sqrt(pow(x[i],2)+pow(y[i],2)),3);
        x[i+1]=x[i]+vx_1*h;
        vx_2=vx_1+1/Mh*fx*h;
        y[i+1]=y[i]+vy_1*h;
        vy_2=vy_1+1/Mh*fy*h;

        //printf("%f \t %f\n", x[i], y[i]);
		fprintf(f,"%f \t %f\n", x[i], y[i]);

        vx_1=vx_2;
        vy_1=vy_2;
        t+=h;
        i++;
    }
}

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
    double h=1000.0;

    double* x=(double*)malloc(step, sizeof(double));
    double* y=(double*)malloc(step, sizeof(double));

    x[0]=0;
    y[0]=apog;

    euler(x,y,h,v_apog,0,step);
    printf("az euler.dat tartalmazza a megoldast \n");
    free(x);
    free(y);

    return 0;
}