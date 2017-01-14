#include <iostream>
#include <stdio.h>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<int,int> l,const pair<int,int> r)
{
    return l.first<r.first;
}
int main()
{
    
    while(1)
    {
        int n,m;
        cin>>n>>m;
        if(n==0&&m==0)
            break;
        bool flag=false;
        bool bb[1000000];
        memset(bb,false,sizeof(bb));
        vector <pair<int,int> > v;
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b));

             }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            for(int k=0;k*c+b<=1000000;k++)
                v.push_back(make_pair(k*c+a,k*c+b));
         }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++)
        {
            int a=v[i].first,b=v[i].second;
            for(int j=a;j<=b;j++)
            {
                if(j!=b&&bb[j])flag=true;
               if(j!=b) bb[j]=true;
            }
        }

        if(!flag)cout<<"NO CONFLICT"<<endl;
        else cout<<"CONFLICT"<<endl;
    }
  
}
