#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
    int cnt=0;
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        cnt++;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        //sort(a,a+n);

        int m;
        cin>>m;

        cout<<"Case "<<cnt<<":"<<endl;
        while(m--)
        {
            int q;
            int mi=10000000,ind1,ind2;

            cin>>q;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j){
                    int temp=a[i]+a[j];
                 if(abs(temp-q)<mi){
                    mi=abs(temp-q);
                    ind1=i;
                    ind2=j;
                }
              }
                }
            }
            int sum=a[ind1]+a[ind2];
            cout<<"Closest sum to "<<q<<" is ";
            cout<<sum<<"."<<endl;
        }
      }

}
