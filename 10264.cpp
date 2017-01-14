#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool comp(int l,int r)
{
    return l>r;
}
int main()
{

    int n;
    while(cin>>n)
    {
        int mx=(1<<n)-1;
        int w[mx+1];
        int sumw[mx+1];
        memset(sumw,0,sizeof(sumw));

        for(int i=0;i<=mx;i++)
        {
            cin>>w[i];
        }

        for(int i=0;i<=mx;i++)
        {
            int nn=n-1;
            while(nn>=0)
            {
                sumw[i]+=w[i^(1<<nn)];
                nn--;
            }

        }
        int best=0;
        for(int i=0;i<=mx;i++)
        {
            int nn=n-1;
            int mmx=0;
            while(nn>=0)
            {
                mmx=max(mmx,sumw[i^(1<<nn)]);
                nn--;
            }
            best=max(best,mmx+sumw[i]);
        }
                
        cout<<best<<endl;
    }
}
        


        
