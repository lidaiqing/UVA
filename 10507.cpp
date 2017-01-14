#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

class UnionFind{

    private: vector<int> p,rank;
    public:
             UnionFind(int N){ 
                 rank.assign(N,0);
                 p.assign(N,0);
                 for(int i=0;i<N;i++)
                     p[i]=i;
             }
             int findSet(int i)
             {
                 return (p[i]==i)? i : (p[i]=findSet(p[i]));
             }
             bool isSameSet(int i,int j)
             {
                 return (findSet(i)==findSet(j));
             }
             bool isConnect(int i,int j)
             {
                 if(p[i]==j||p[j]==i)return true;
                 return false;
             }
             void unionSet(int i,int j){
                 if(!isSameSet(i,j)) {
                    // cout<<i<<"  "<<j<<endl;

                     int x=findSet(i),y=findSet(j);
                     if(rank[x]>rank[y])p[y]=x;
                     else{
                         p[x]=y;
                         if(rank[x]==rank[y])
                         {
                             rank[y]++;
                         }
                     }
                 }
             }
};

int main()
{

    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {

    int m;
    cin>>m;

    vector<int> con[26];
    
    //UnionFind uSet (26);

    bool check[26];
    memset(check,false,sizeof(check));
    bool wakeCheck[26];
    memset(wakeCheck,false,sizeof(wakeCheck));
    for(int i=0;i<3;i++)
    {
        char temp;
        cin>>temp;
        wakeCheck[temp-'A']=true;
    }

    for(int i=0;i<m;i++)
    {
        char temp1,temp2;

        cin>>temp1>>temp2;
        con[temp1-'A'].push_back(temp2-'A');
        con[temp2-'A'].push_back(temp1-'A');
     // uSet.unionSet(temp1-'A',temp2-'A');
    }
    
    
    int cnt=0;
    bool flag=false;
    while(1)
    {

        flag=false;
        vector <int> wake;
        for(int i=0;i<26;i++)
        {
            int time=0;
            if(wakeCheck[i])continue;
            for(int j=0;j<con[i].size();j++)
            {
                if(wakeCheck[con[i][j]])
                    time++;
                if(time>=3)
                {
                    wake.push_back(i);
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)break;
        for(int i=0;i<wake.size();i++)
            wakeCheck[wake[i]]=true;
        cnt++;
    }
    int cntAwake=0;
    for(int i=0;i<26;i++)
        if(wakeCheck[i])cntAwake++;

    if(cntAwake<n)cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
    else 
    cout<<"WAKE UP IN, "<<cnt<<", YEARS"<<endl;
    }
    
}

    

            
        
    

