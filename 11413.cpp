#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long ve[1005];
long long n,m;
bool can(long long c)
{
    long long num=1;
    long long left=c;
    for(long long i=0;i<n;i++)
    {
        
        if(ve[i]<=left){
            left-=ve[i];
        }
        else{
            if(ve[i]<=c){
            left=c-ve[i];
            num++;
            }
            else return false;
        }
    }
    if(num>m)return false;
    else return true;
}

int main()
{

    
    while(cin>>n)
    {
        cin>>m;
        for(int i=0;i<n;i++)
            cin>>ve[i];

        long long low=0,high=1000005,mid,ans=100000000000;
 
        while(low<=high)
        {
            
            mid=(low+high)/2;

            if(can(mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        cout<<ans<<endl;
    }
}



