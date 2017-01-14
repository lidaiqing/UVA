#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main()
{


    int cnt=1;
    for(int i=1;4*i<=2000;i++){
        for(int j=i;i+3*j<=2000;j++){
            for(int k=j;i+j+2*k<=2000;k++){
                int a=i,b=j,c=k;
                long long p=(a*b*c);
                long long s=(a+b+c);

                if(p<=1000000)continue;
                long long d=(1000000*s)/(p-1000000);

                if(d<c||s+d>2000)continue;
                if(fabs((a+b+c+d)/100.0-(a*b*c*d)/100000000.0)<1e-9)
                    printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",a/100.0,b/100.0,c/100.0,d/100.0);
            }
        }
    }
}
