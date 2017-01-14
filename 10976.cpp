#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <stdlib.h>
using namespace std;

int main()
{

    int k;
    while(cin>>k)
    {
        
        vector <pair<long long,long long> > v;

        for(int i=k+1;i<=2*k;i++)
                if((long long)(k*i)%abs(i-k)==0&&i<=(k*i)/abs(i-k))
                    v.push_back(make_pair(i,(long long)k*i/abs(i-k)));

        cout<<v.size()<<endl;

        for(int i=0;i<v.size();i++)
        cout<<"1/"<<k<<" = "<<"1/"<<v[i].second<<" + "<<"1/"<<v[i].first<<endl;
    }
}
