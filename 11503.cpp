#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
class UnionFind{

    private: vector<int> p,rank,setNum;
    public:
             UnionFind(int N){ 
                 rank.assign(N+1,0);
                 p.assign(N+1,0);
                 setNum.assign(N+1,1);
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
             int cntSet(int i)
             {
                 return setNum[findSet(i)];
             }
             void unionSet(int i,int j){
                 if(!isSameSet(i,j)) {

                     int x=findSet(i),y=findSet(j);
                     if(rank[x]>rank[y]){
                          p[y]=x;
                          setNum[x]+=setNum[y];
                     }
                     else{
                         p[x]=y;
                         setNum[y]+=setNum[x];
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
    while(t--)
    {
        int f;
        cin>>f;

        UnionFind uSet (100001);
        map<string,int> mymap;
        int cnt=0;
        for(int i=0;i<f;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            int num1,num2;
            if(mymap.count(s1))
            {
                num1=mymap[s1];
            }
            else
            {
                num1=cnt+1;
                cnt++;
                mymap.insert(make_pair(s1,num1));
            }
            if(mymap.count(s2))
            {
                num2=mymap[s2];
            }
            else
            {
                num2=cnt+1;
                cnt++;
                mymap.insert(make_pair(s2,num2));
            }
            uSet.unionSet(num1,num2);
            cout<<uSet.cntSet(num1)<<endl;
        }
    }
}

            
                
                
            


