/* para compilar es: cc cuenta.c -o cuenta.x  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(int argc, char** argv){
    clock_t start, stop;
    double diff_t;
    start = clock();
    char leer[strlen(argv[1])],escribir[strlen(argv[2])],tiempo[strlen(argv[3])];
    strcpy(leer, argv[1]);
    strcpy(escribir, argv[2]);
    strcpy(tiempo, argv[3]);
    FILE *in;
    char var[100];
    int a,b,c,d,e;
    a=b=c=d=e=0;
    int ar,br,cr,dr;
    ar=br=cr=dr=0;
    int k;
    in = fopen(leer, "r");
    if(!in){
        printf("No se encontro: %s\n", leer);
        exit(1); }
    int i=0;
    while((var[0] = fgetc(in)) != EOF){
        k=atoi(var);
        //printf("%c  %d \n", var[0],k);
        if(k==1){
            a=a+1;
            br=cr=dr=0;
            ar=1;
        }
        else if(k==2&&ar==1){
            b=b+1;
            ar=cr=dr=0;
            br=1;
        }
        else if(k==3&&br==1){
            c=c+1;
            ar=br=dr=0;
            cr=1;
        }
        else if(k==4&&cr==1){
            d=d+1;
            ar=br=cr=0;
            dr=1;
        }
        else if(k==5&&dr==1){
            e=e+1;
            ar=br=cr=dr=0;
        }
        else{
            ar=br=cr=dr=0;
        }
    }
    //printf("%d  %d  %d  %d  %d\n", a,b,c,d,e);
    fclose(in);
    stop = clock();
    FILE *out = fopen(escribir,"w");
    fprintf(out,"%d\n",a);
    fprintf(out,"%d\n",b);
    fprintf(out,"%d\n",c);
    fprintf(out,"%d\n",d);
    fprintf(out,"%d\n",e);
    fclose(out);
    
    
    diff_t = (double)(stop - start) / CLOCKS_PER_SEC;
    FILE *out1 = fopen(tiempo,"a");
    fprintf(out1,"%f\n",diff_t);
    fclose(out);
    return 0;
}

