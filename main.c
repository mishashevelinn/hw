#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rand_();
void fill_array(double array [],int n);
double mean(double array [],int n);
double sd(double array [], int n);
double chek_sd(double array [], int n,double sd);

int main(){
    srand(10);
    int n=1000000;
    static double Ar [1000000];
    fill_array(Ar, n);
    FILE *fp;

    fp = fopen("C:\\Users\\Michael\\Desktop\\gauss.txt","w");
    if(fp == NULL) //if file does not exist, create it
    {
        fp = fopen("gauss.txt", "w");
    }
    for(int i = 0; i< n; i++){
        fprintf(fp, "%f\n", Ar[i]);
    }
    fclose(fp);
    printf("mean = %f, sd = %f\n",mean(Ar,n), sd(Ar, n));
    printf("(-3, 3) : %f\n", chek_sd(Ar, n, 3));
    printf("(-2, 2) : %f\n", chek_sd(Ar, n, 2));
    printf("(-1, 1) : %f\n", chek_sd(Ar, n, 1));
}

double rand_() {
    int U1 = rand();
    int U2 = rand();
    double D1;
    double D2;
    double res;
    double pi= acos(-1);
    while (U1==0) {
        U1= rand();
    }
    while (U2==0) {
        U2=rand();
    }
    D1= ((double) U1/ RAND_MAX);
    D2= ((double) U2/ RAND_MAX);
    res= sqrt(-2*log(D1))*cos(2*pi*D2);
    return res;
}

void fill_array(double array [],int n){
    int i;
    for(i=0; i<n; i++) {
        array[i]= rand_();
    }
}

double mean(double array [],int n){
    double sum=0;
    int i;
    for (i=0; i<n; i++){
        sum+= array[i];
    }
    sum/= (double) n;
    return sum;
}

double sd(double array [], int n) {
    double res=0;
    double avg= mean(array, n);
    int i;
    for (i=0; i<n; i++){
        res+= (array[i]-avg)*(array[i]-avg);
    }
    res/=(double) n;
    return sqrt(res);
}

double chek_sd(double array [], int n,double new_sd){
    int i;
    double res;
    new_sd*=sd(array , n);
    for(i=0; i<n; i++){
        if (array[i]>= (-1*new_sd) && array[i]<=new_sd){
            res+=1;
        }
    }
    res/= (double)n;
    return res;
}