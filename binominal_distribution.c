#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long fatorial(long n,long k){
    long i;
    for(i=1;n>k;n--){
        //printf("fatorial: %ld %ld\n",n,k);
        i=i*n;
        
    }
    return i;
}
long binomial(long n,long k){
    if(k>n) return 0;
    long x,y;
    if((n-k)>k){
        x=fatorial(n,n-k);
        y=fatorial(k,1);
    }
    else{
        x=fatorial(n,k);
        y=fatorial(n-k,1);
    }
    //printf("%ld %ld\n",x,y);
    return x/y;
}

float distribution(long k, long n, float p){
    if(k>n||p<=0||p>=1) return 0;
    float x = binomial(n,k);
    x=x*pow(p,k)*pow((1-p),n-k);
    return x;
}
//tirar pelo menos k vezes, soma as distribuições de k até n
float greater_than(long k, long n, float p){
    float i;
    for(i=0;k<=n;k++)
        i=i+distribution(k,n,p);
    return i;
}
int main(){
    
    int n,k,i;
    
    printf("\n");
    for(n=1;n<=30;n++){
        printf("n= %d\n",n);
        for(k=1;k<=6;k++){
            printf("11: %.2f%%\t",greater_than(k,n,(double)27/216)*100);
        }
        printf("\n");
        for(k=1;k<=6;k++){
            printf("15: %.2f%%\t",greater_than(k,n,(double)10/216)*100);
        }
        printf("\n");
    }
    
    
    return 0;
}