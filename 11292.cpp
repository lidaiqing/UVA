#include <iostream>
#include <stdio.h>
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

        vector<int> head,knight;

        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            head.push_back(temp);
        }
        for(int i=0;i<m;i++)
        {
            int temp;
            cin>>temp;
            knight.push_back(temp);
        }

        sort(head.begin(),head.end());
        sort(knight.begin(),knight.end());

        int last=-1;
        int ans=0;
        bool flag;
        for(int i=0;i<head.size();i++)
        {
            flag=false;

            for(int j=last+1;j<knight.size();j++)
            {
                if(knight[j]>=head[i])
                {
                    last=j;
                    ans+=knight[j];
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)cout<<"Loowater is doomed!"<<endl;
        else cout<<ans<<endl;
    }
}
