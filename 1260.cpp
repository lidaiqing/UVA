#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()

{

    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;

        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        int b[n];
        memset(b,0,sizeof(b));
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(a[j]<=a[i])
                    b[i-1]++;
        int sum=0;
        for(int i=0;i<n-1;i++)
            sum+=b[i];

        cout<<sum<<endl;
    }
}
