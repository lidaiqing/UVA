#include <iostream>
#include <stdlib.h>
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
        int list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];

        int lis[n],lds[n];
        for(int i=0;i<n;i++)
        {
            lis[i] = 1;
            lds[i] = 1;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            int mxi = -1,mxd = -1;

            for(int j=n-1;j>i;j--){
                if(list[j] < list[i])
                {
                    if(lis[j] + 1 > mxi){
                        mxi = lis[j] + 1;
                        lis[i] = mxi;
                    }
                }
                if(list[j] > list[i])
                {
                    if(lds[j] + 1 > mxd){
                        mxd = lds[j] + 1;
                        lds[i] = mxd;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans,lis[i] + lds[i] - 1);
        cout<<ans<<endl;
    }
}
