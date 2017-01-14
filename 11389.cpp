#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

bool comp(int l, int r)
{
    return l>r;
}

int main()
{


    while(1)
    {
        int n,d,r;
        cin>>n>>d>>r;
        if(n==0&&d==0&&r==0)break;

        vector<int> day,night;

        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            day.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            night.push_back(temp);
        }
        
        sort(day.begin(),day.end());
        sort(night.begin(),night.end(),comp);

        int ans=0;

        for(int i=0;i<n;i++)
        {
            int temp=day[i]+night[i]-d;
            if(temp>0)ans+=temp;
        }

        cout<<ans*r<<endl;
    }
}
