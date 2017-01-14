#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        int d;
        cin>>d;
        string name[d];
        long long L[d],H[d];

        for(int i=0;i<d;i++)
        {
            cin>>name[i];
            cin>>L[i]>>H[i];
        }

        int q;
        cin>>q;
        while(q--)
        {
            long long p;
            cin>>p;

            bool flag1=false,flag2=false;
            int ans;

            for(int i=0;i<d;i++)
            {
                if(p>=L[i]&&p<=H[i])
                {
                    //cout<<i<<endl;
                    if(!flag1)flag1=true;
                    else flag2=true;
                    ans=i;
                }
            }
            if(flag1&&!flag2)cout<<name[ans]<<endl;
            else cout<<"UNDETERMINED"<<endl;
        }
        if(t)cout<<endl;
    }
}
