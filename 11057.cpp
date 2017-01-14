#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{


    int n;
    while(cin>>n)
    {

        vector<int> p;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            p.push_back(temp);
        }

        sort(p.begin(),p.end());

        int m;
        cin>>m;

        int diff=10000000;
        int ans1,ans2;
        for(int i=0;i<p.size()-1;i++)
        {
            vector<int>::iterator low;
            int nd=m-p[i];
            if(nd>0){
            low=lower_bound(p.begin()+i+1,p.end(),nd);

            if(p[low-p.begin()]==nd){
                
                if(abs(p[low-p.begin()]-p[i])<diff){
                    diff=abs(p[low-p.begin()]-p[i]);
                    ans1=p[i];
                    ans2=p[low-p.begin()];
                }
              }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);
    }
}

        
