//racz gergely
//goz1np
//rk4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(double* k)
{
    for (int i=0;i<9;i++)
    {
        printf(" %f ", k[i]);
    }
    printf("\n");
}

double* diff(double* r)
{
    double* d =(double*)malloc(9*sizeof(double));
    double Mf=5.9736*pow(10,24);
    double Mh=7.349*pow(10,22);
    double G=6.67384*pow(10,-11);
    d[0]=1.0;//ido
    d[1]=-G*Mf*(r[5]-r[7])/pow(sqrt(pow(r[5]-r[7],2)+pow(r[6]-r[8],2)),3);//hxdiff
    d[2]=-G*Mf*(r[6]-r[8])/pow(sqrt(pow(r[5]-r[7],2)+pow(r[6]-r[8],2)),3);//hydiff
    d[3]=-G*Mh*(r[7]-r[5])/pow(sqrt(pow(r[5]-r[7],2)+pow(r[6]-r[8],2)),3);//fxdiff
    d[4]=-G*Mh*(r[8]-r[6])/pow(sqrt(pow(r[5]-r[7],2)+pow(r[6]-r[8],2)),3);//fydiff
    d[5]=r[1];//hvx
    d[6]=r[2];//hvy
    d[7]=r[3];//fvx
    d[8]=r[4];//fvy
    //printf("diff: %f |", d[0]);
    return d;
}

double* euler(double* r, double h, double* k,double s)
{
    double* lepes1=(double*)malloc(9*sizeof(double));
    double* lepes2=(double*)malloc(9*sizeof(double));
    for(int i=0;i<9;i++)
    {
        lepes1[i]=r[i]+k[i]*s;
    }
    //printf("lepes 1: %d |", lepes1[0]);

    lepes2=diff(lepes1);
    for(int i=0;i<9;i++)
    {
        lepes2[i]=lepes2[i]*h;
    }
            //printf("lepes 2: %d |\n", lepes2[0]);
    return lepes2;
}


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

    //printf("%d", n);
    
    //double* matrix=(double*)malloc(n*9*sizeof(double));
    double* k1=(double*)malloc(n*sizeof(double));
    double* k2;
    double* k3;
    double* k4;
    //double b;

    FILE* f;
    f=fopen("rk4.dat","w");

    for(int i=0; i<n; i++)
    {
        //printf("\n%d\n",i);
        /*for(int j=0;j<9;j++)
        {
            fprintf(f, "%f ",r[j]);
        }
        fprintf(f, "\n");*/


        //printf("k1: \n");
        k1=euler(r,h,k1,0);
       // print(k1);
        //printf("k2: \n");
        k2=euler(r,h,k1,0.5);
        //print(k2);
        //printf("k3: \n");
        k3=euler(r,h,k2,0.5);
        //print(k3);
        //printf("k4: \n");
        k4=euler(r,h,k3,1);
        //print(k4);

        //printf("r elotte: \n");
        //print(r);
        for(int j=0; j<r_size; j++)
        {
            fprintf(f, "%f", r[j]);
            if (j==0)
            {
                r[j]+=1.0;
            }else{
                r[j]=r[j]+k1[j]*1/6+k2[j]*1/3+k3[j]*1/3+k4[j]*1/6;
            }
        }
        fprintf(f,"\n");
        //printf("r utana: \n");
        //print(r);
        free(k1);
        free(k2);
        free(k3);
    }

    /*printf("%d", n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r_size;j++)
        {
            fprintf(f,"%f ",matrix[i*r_size+j]);
        }
    fprintf(f,"\n");
    }*/
    printf("az rk4.dat tartalmazza a megoldast");
    return 0;
}
