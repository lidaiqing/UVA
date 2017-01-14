#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    string blank;
    cin.ignore();
    getline(cin,blank);

    while(t--)
    {
        
    
        vector<string> refrence;
        map<string,int> mymap;
        string s;
        long long sum=0;
        while(getline(cin,s))
        {
            if(s==blank)break;
            sum++;
            if(mymap.count(s)<=0)
            {
                mymap.insert(make_pair(s,1));
                refrence.push_back(s);
            }
            else
            {
                mymap[s]++;
                //cout<<mymap[s]<<endl;
            }
        }
        
        sort(refrence.begin(),refrence.end());
        for(int i=0;i<refrence.size();i++)
        {
            cout<<refrence[i]<<" ";
            double cnt=(double)mymap[refrence[i]]*100/sum;
            printf("%.4f\n",cnt);
        }
        if(t)printf("\n");
    }
}
        


