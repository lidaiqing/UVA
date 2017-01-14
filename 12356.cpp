#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct link{
    int l,r;
};
int main()
{
    ios::sync_with_stdio(false);
    while(1)
    {
        int s,b;
        cin>>s>>b;
        if(s==0&&b==0)break;
        link ll[s+1];

        if(s==1){
            ll[1].l=-1;
            ll[1].r=-1;
        }
        else{

                ll[1].l=-1;
        ll[1].r=2;
        for(int i=2;i<=s-1;i++)
        {
            ll[i].l=i-1;
            ll[i].r=i+1;
        }
        ll[s].l=s-1;
        ll[s].r=-1;
        }
        for(int i=1;i<=b;i++)
        {
            int l,r;
            cin>>l>>r;
            if(ll[l].l==-1)cout<<"* ";
            else cout<<ll[l].l<<" ";
            if(ll[r].r==-1)cout<<"*"<<endl;
            else cout<<ll[r].r<<endl;
            ll[ll[l].l].r=ll[r].r;
            ll[ll[r].r].l=ll[l].l;
        }

             cout<<"-"<<endl;
    }
}

