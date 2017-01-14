#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
bool mycomp(pair<double,double> l,pair<double,double> r)
{

    double ll=l.first/l.second;
    double rr=r.first/r.second;

    return ll<rr;
}
int main()
{

    while(1)
    {

        int f,r;
        cin>>f;
        if(f==0)break;
        cin>>r;

        double ff[f],rr[r];
        for(int i=0;i<f;i++)
            cin>>ff[i];
        for(int i=0;i<r;i++)
            cin>>rr[i];

        vector <pair<double,double> > v;
        for(int i=0;i<r;i++)
            for(int j=0;j<f;j++)
                v.push_back(make_pair(rr[i],ff[j]));
        
       // vector <double>::iterator it;

        //it=unique (v.begin(),v.end());
      //  v.resize(distance(v.begin(),it));
        sort(v.begin(),v.end(),mycomp);
        
        double mx=-1.0;
        for(int i=1;i<v.size();i++)
        {
            double temp=v[i].first*v[i-1].second/(v[i].second*v[i-1].first);
            //cout<<temp<<endl;
            mx=max(mx,temp);
        }

        printf("%.2f\n",mx);
    }
}

