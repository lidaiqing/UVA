#include <iostream>
#include <stdlib.h>

using namespace std;
typedef long long ll;
int main()
{

    ll n,l,u;
    while(cin>>n)
    {
        cin>>l>>u;

        ll ans=0;
        for (int i = 32; i >=0; i--)
        {
            ll state = n & (1LL << i);
            if(state)
            {
                ll temp = state -1;
                temp |= ans;
                if(temp < l){
                    ans |= state;
                }
            }
            else
            {
                ll temp = ans;
                temp |= (1LL << i);
                if(temp <= u)
                    ans = temp;
            
            }
        }
        cout<<ans<<endl;

    }
}
