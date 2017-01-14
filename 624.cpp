#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
int n,track;
int list[25];
bool comp(int l,int r)
{
    return l<r;
}

int main()
{
    ios::sync_with_stdio(false);

    while(cin>>n)
    {
        
        cin>>track;
        for(int i=0;i<track;i++)
            cin>>list[i];
        int mi=100000;
        vector <long long> ans;
        long long sum;
        for(int i=0;i<(1<<(track+1));i++)
        {
            sum=0;
            for(int j=0;j<track;j++)
                if(i&(1<<j))sum+=list[j];
            if(abs(n-sum)<mi&&n>=sum){
                mi=abs(n-sum);
                ans.clear();
                for(int j=0;j<track;j++)
                    if(i&(1<<j))ans.push_back(j);
            }
            else if(abs(n-sum)==mi&&(n>=sum))
            {
                vector<long long> temp;
                for(int j=0;j<track;j++)
                    if(i&(1<<j))temp.push_back(j);
                int size=min(temp.size(),ans.size());
                bool flag=false;
                for(int j=0;j<size;j++)
                    if(temp[j]<ans[j]){
                        flag=true;
                        break;
                    }
                if(flag){
                    ans.clear();
                    for(int i=0;i<temp.size();i++)
                        ans.push_back(temp[i]);
                }
            }
        }

        sum=0;
        vector<int> temp;
        for(int i=0;i<ans.size();i++)
            temp.push_back(list[ans[i]]);
        //sort(temp.begin(),temp.end());
        for(int i=0;i<ans.size();i++)
        {
            cout<<temp[i]<<" ";
            sum+=list[ans[i]];
        }
        cout<<"sum:"<<sum<<endl;
    }
}


