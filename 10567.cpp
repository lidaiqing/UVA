#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> v[256];
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        v[s[i]].push_back(i);

    int q;
    cin>>q;
    while(q--)
    {
        string ss;
        cin>>ss;

        bool flag=true;
        int ind=-1;
        for(int i=0;i<ss.size()&&flag;i++){
            
            vector<int>::iterator up=upper_bound(v[ss[i]].begin(),v[ss[i]].end(),ind);

            if(up==v[ss[i]].end())flag=false;
            int temp=up-v[ss[i]].begin();
            ind=v[ss[i]][temp];

        }
        if(!flag){
            cout<<"Not matched"<<endl;
        }
        else{
            int st=v[ss[0]][0];
            cout<<"Matched "<<st<<" "<<ind<<endl;
        }
    }
}

