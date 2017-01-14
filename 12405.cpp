#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{


    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        cas++;
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool check[n];
        for(int i=0;i<n;i++)
            check[i]=true;

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='#')check[i]=false;
        }

        for(int i=0;i<n;i++)
        {
            if(check[i])
            {
                if(i+2<n&&check[i+2])
                {
                    check[i]=false;
                    check[i+1]=false;
                    check[i+2]=false;
                    cnt++;
                }
                else
                {
                    check[i]=false;
                    check[i+1]=false;
                    cnt++;
                }
            }
        }
        cout<<"Case "<<cas<<": "<<cnt<<endl;
    }
}



