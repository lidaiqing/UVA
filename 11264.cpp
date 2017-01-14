#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>

#define  ll long long
using namespace std;
vector <ll> type;
bool check[1005];
int n;
ll withdrawal(ll money)
{
    ll cnt=0;
    while(money>0)
    {
        vector<ll>::iterator low;
        low = lower_bound(type.begin(),type.end(),money);
       if(low!=type.end()) {
           if(type[low-type.begin()]<=money) money-=type[low-type.begin()];
           else {
               low--;
               money-=type[low-type.begin()];
           }
       }
       else {
           money-=type.back();
           low--;
       }
       //cout<<type[low-type.begin()]<<" "<<money<<endl;
        if(!check[low-type.begin()])
        {
            check[low-type.begin()]=true;
            cnt++;
        }
        if(cnt==n)return cnt;
    }
    return cnt;
}
        

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        type.clear();
        cin>>n;
        ll sum=1;
        for(int i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            type.push_back(temp);
        }
        
        //sort(type.begin(),type.end());
        ll ans=2;
        for(int i=1;i<n-1;i++)
        {
            if(sum<type[i]&&sum+type[i]<type[i+1])
            {
                ans++;
                sum+=type[i];
            }
        }
       // cout<<withdrawal(63)<<endl;

        cout<<ans<<endl;
    }
}
        



        
