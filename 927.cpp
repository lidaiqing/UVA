#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{


    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        int c[n+1];
        for(int i=0;i<=n;i++)
            cin>>c[i];

        long long d,k;
        cin>>d>>k;

        long long ans=ceil(double((sqrt(1+(double)k*8/d)-1)/2));

        long long res=0;

        for(int i=0;i<=n;i++)
            res+=c[i]*pow(ans,i);

        cout<<res<<endl;
    }
}

        
