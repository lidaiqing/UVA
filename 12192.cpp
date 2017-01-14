#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    while(1)
    {

        int n,m;
        cin>>n>>m;
        if(n==0&&m==0)break;

        vector<int> mp[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                int temp;
                cin>>temp;
                mp[i].push_back(temp);
            }
        }
        vector<int> col[m];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                col[i].push_back(mp[j][i]);
            

        int q;
        cin>>q;
        while(q--)
        {
            int l,h;
            cin>>l>>h;
            int mx=0;

            for(int i=0;i<n;i++)
            {
                vector<int>::iterator low;
                low=lower_bound(mp[i].begin(),mp[i].end(),l);
                if(low!=mp[i].end()&&mp[i][low-mp[i].begin()]<=h){
                  int side=mx;
                  for(int j=mx;low-mp[i].begin()+j<m&&i+j<n;j++)
                  {
                      if(mp[i+j][low-mp[i].begin()+j]<=h)
                          side++;
                      else break;
                  }
                   mx=max(mx,side);
                }
            }
            cout<<mx<<endl;
        }
        cout<<"-"<<endl;
    }
}


