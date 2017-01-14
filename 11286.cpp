#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    while(1)
    {

        int n;
        scanf("%d",&n);
        if(n==0)break;
        map<vector<long long>,int> mymap;
        int mx=1;

        for(int j=0;j<n;j++)
        {

        long long key=1;
        vector<long long >v;
        for(int i=0;i<5;i++)
        {
            int temp;
            scanf("%d",&temp);
            key*=temp*5;
            v.push_back(temp);
           
        }
        sort(v.begin(),v.end());
        if(mymap.count(v)>0)
        {
            mymap[v]++;
            if(mymap[v]>mx)mx=mymap[v];
        }
        else
        {
            mymap.insert(make_pair(v,1));
        }
        }
        int ans=0;
        for(map<vector<long long> ,int>::iterator it=mymap.begin();it!=mymap.end();it++)
            if(it->second==mx)ans+=mx;
        printf("%d\n",ans);
    }
}
        
        


    
