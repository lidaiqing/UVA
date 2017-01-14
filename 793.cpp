#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class UnionFind{

    private: vector<int> p,rank;
    public:
             UnionFind(int N){ 
                 rank.assign(N+1,0);
                 p.assign(N+1,0);
                 for(int i=1;i<=N;i++)
                     p[i]=i;
             }
             int findSet(int i)
             {
                 return (p[i]==i)? i : (findSet(p[i]));
             }
             bool isSameSet(int i,int j)
             {
                 return (findSet(i)==findSet(j));
             }
             void unionSet(int i,int j){
                 if(!isSameSet(i,j)) {
                    // cout<<i<<"  "<<j<<endl;

                     int x=findSet(i),y=findSet(j);
                     if(rank[x]>rank[y])p[y]=x;
                     else{
                         p[x]=y;
                         if(rank[x]==rank[y])
                             rank[y]++;
                     }
                 }
             }
};

int main()
{
    int t;
    cin>>t;
    string blank;
    cin.ignore();
    getline(cin,blank);

    while(t--)
    {
    int n;
    cin>>n;
    UnionFind uSet (n+10);
    
    int cntRight=0,cntWrong=0;

    string temp;
    cin.ignore();
    while(getline(cin,temp))
    {
        if(temp==blank)break;
        if(temp[0]=='c')
        {
            int a,b;
            a=temp[2]-'0';
            b=temp[4]-'0';
            
            uSet.unionSet(a,b);
            //cout<<uSet.isSameSet(a,b)<<endl;
        }
        else if(temp[0]=='q')
        {
            int a,b;
            a=temp[2]-'0';
            b=temp[4]-'0';
            
            //cout<<uSet.isSameSet(a,b)<<endl;
            if(uSet.isSameSet(a,b))cntRight++;
            else cntWrong++;
            
        }
    }

    cout<<cntRight<<","<<cntWrong<<endl;
    if(t!=0)cout<<endl;
    }
}


