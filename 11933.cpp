#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    while(1)
    {
        int n;
        cin>>n;
        if(n==0) break;
        int a=0,b=0;
        int cnt=0;
        if(n&1){
            a=1;
            cnt++;
        }
        int nth=0;
        while(n!=0)
        {
            n>>=1;
            nth++;
            if(n&1){
                cnt++;
                if(cnt%2==0)
                    b|=(1<<nth);
                else 
                    a|=(1<<nth);
            }
        }
        cout<<a<<" "<<b<<endl;
    }
}
