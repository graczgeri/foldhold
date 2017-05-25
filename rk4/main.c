//racz gergely
//goz1np
//rk4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>






int main()
{
    double Mf=5.9736*pow(10,24);
    double Mh=7.349*pow(10,22);
    
    size_t r_size = 9;
    
    double* r=(double*)malloc(r_size*sizeof(double));
    r[0]=0.0; //t ido
    r[1]=0.0; //Hold v_x
    r[2]=968; // Hold v_y Foldtavolban
    r[3]=0.0; //Fold v_x
    r[4]=-Mh/Mf*964 ; //Fold v_y
    r[5]=-405500000; //Hold x Foldtavolban
    r[6]=0.0; // Hold y
    r[7]=0.0; // Fold x
    r[8]=0.0; // Fold y
    double h=100;
    int n=60*24*30;

    printf("%d", n);
    
    double* matrix=(double*)malloc(n*9*sizeof(double));
    double* k1=(double*)malloc(n*sizeof(double));
    double* k2;
    double* k3;
    double* k4;
    double b;