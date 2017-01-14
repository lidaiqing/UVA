#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
double p,q,r,s,t,u;

double check(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{


    
    while(cin>>p){

        cin>>q>>r>>s>>t>>u;
        
        double low,high,mid;
        low=0,high=1;
        double ans=-1;
        while(fabs(high-low)>1e-12)
        {
            mid=(low+high)/2;
            
            if(fabs(check(mid))>1e-8){
                if(check(mid)>0)
                    low=mid;
                else
                    high=mid;
            }
            else
            {
                ans=mid;
                break;
            }
        }
        
        if(ans==-1)
        {
            cout<<"No solution"<<endl;
        }
        else printf("%.4f\n",ans);
    }
}
    

