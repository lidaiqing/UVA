#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

int t,n;
int list[15];
vector <int> temp;
map <vector<int>, bool> mp;
bool flag;
bool check[15];
bool comp( int l, int r)
{
    return (l>r);
}

void backtrack(int st,int sum)
{
    if(sum==t){
       // cout<<sum<<endl;

        flag=true;
        vector<int > temp1;
        for(int i=0;i<temp.size();i++)
            temp1.push_back(temp[i]);
        sort(temp1.begin(),temp1.end(),comp);
        if(mp[temp1])return;
           mp[temp1]=true;
        for(int i=0;i<temp1.size()-1;i++)
            cout<<temp1[i]<<"+";
        cout<<temp1[temp1.size()-1]<<endl;
        return;
        
    }
    else if(sum<t){
        for(int i=st;i<n;i++)
        {
            if(!check[i]){
                check[i]=true;
                temp.push_back(list[i]);
                backtrack(st+1,sum+list[i]);
                temp.erase(temp.begin()+temp.size()-1);
                check[i]=false;
            }
        }
    }
    else return;
}
int main()
{
    ios::sync_with_stdio(false);
    while(1)
    {
        cin>>t>>n;
        temp.clear();
        flag=false;
        if(t==0&&n==0)break;
        for(int i=0;i<n;i++)
            cin>>list[i];
        sort(list,list+n,comp);
        bool check[n];
        memset(check,false,sizeof(check));
        
        cout<<"Sums of "<<t<<":"<<endl;
         backtrack(0,0);

        if(!flag)cout<<"NONE"<<endl;
    
    }
}
        
