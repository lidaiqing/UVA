#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        int n,p;
        cin>>n>>p;
        int list[p];
        for(int i=0;i<p;i++)
            cin>>list[i];

        bool flag=false;
        for(int i=0;i<(1<<(p+1));i++)
        {
            int sum=0;
            for(int j=0;j<p;j++)
            {
                if(i&(1<<j))sum+=list[j];
            }
            if(sum==n){
                flag=true;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
