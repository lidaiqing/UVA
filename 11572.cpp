#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{


    int t;
    scanf("%d",&t);

    while(t--)
    {

        long long n;
        cin>>n;
        int mx=-1;
        map<long long ,int> mymap;
        int last=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            long long temp;
            cin>>temp;
            if(mymap.count(temp)>0)
            {
                if(mymap[temp]>last)last=mymap[temp];
                int length=i-last;
                mx=max(length,mx);
                mymap[temp]=i;
                cnt=length;
            }
            else
            {
                mymap.insert(make_pair(temp,i));
                cnt++;
                mx=max(mx,cnt);
            }
        }

        cout<<mx<<endl;
    }
}
            
