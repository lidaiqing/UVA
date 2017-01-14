#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long ll;
vector<ll> v[1000005];

int main()
{
    
    ll n,m;
    while(cin>>n>>m)
{

    for(int i=0;i<=n;i++)
    v[i].clear();
    for(ll i=1;i<=n;i++)
    {
        ll temp;
        cin>>temp;

        v[temp].push_back(i);
    }

    for(ll i=1;i<=m;i++)
    {

        ll k,vv;
        cin>>k>>vv;

        if(v[vv].size()>=k)
        {
            cout<<v[vv][k-1]<<endl;
        }
        else
            cout<<"0"<<endl;
    }
}
 return 0;
}
    
