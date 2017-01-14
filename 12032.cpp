#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int rung[100005];
int ori[100005];
int n;
bool can(int k)
{
    
    for(int i=0;i<n;i++)
    {
        //cout<<rung[i]<<" "<<k<<endl;
        if(rung[i]>k)return false;
        if(rung[i]==k)k--;
        if(k<0)return false;
    }
    return true;
}


int main()
{

    int t;
    cin>>t;
    int cnt=1;
    while(t--)
    {

        
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>ori[i];
        rung[0]=ori[0];
        for(int i=1;i<n;i++)
            rung[i]=ori[i]-ori[i-1];

        int low=1,high=100000000,mid,ans=100000000;
       // cout<<can(5)<<endl;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(can(mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        cout<<"Case "<<cnt<<": ";
        cnt++;
        cout<<ans<<endl;
    }
}

