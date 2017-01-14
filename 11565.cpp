#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int t;
    cin>>t;

    while(t--)
    {

        int a,b,c;
        cin>>a>>b>>c;

        bool flag=false;

        for(int x=-100;x<=100&&!flag;x++){
            for(int y=-100;y<=100&&!flag;y++){
                for(int z=-100;z<=100&&!flag;z++){
                    if(x!=y&&x!=z&&y!=z&&x+y+z==a&&x*y*z==b&&x*x+y*y+z*z==c)
                    {
                        cout<<x<<" "<<y<<" "<<z<<endl;
                        flag=true;
                    }
                }
            }
        }
        if(!flag)cout<<"No solution."<<endl;
    }
}
