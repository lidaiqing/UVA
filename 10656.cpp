#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    while(1)
    {

        int n;
        cin>>n;
        if(n==0)break;
        int list[n];
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            cin>>list[i];
            if(list[i]!=0)flag=true;
        }
        if(!flag){
            cout<<"0"<<endl;
        }
        else
        {
            bool first=true;
            for(int i=0;i<n;i++)
            {
                if(list[i]!=0)
                    {
                        if(first)
                        {
                           cout<<list[i];
                           first=false;
                           continue;
                        }
                        else {
                            cout<<" "<<list[i];
                        }
                    }
            }
            cout<<endl;
        }
    }
}
