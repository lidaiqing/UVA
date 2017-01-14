#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>


using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main()
{
    int m,n;
    while(cin>>m>>n)
    {

    vector<vii> adj,tadj;
    adj.assign(m+1,vii());
    tadj.assign(n+1,vii());
    int pos[1001],num[1001];

    for(int i=1;i<=m;i++)
    {
        int r;
        cin>>r;

        for(int j=1;j<=r;j++)
        {
            cin>>pos[j];
        }
        for(int j=1;j<=r;j++)
        {
            cin>>num[j];
        }
        
        for(int j=1;j<=r;j++)
        {
            adj[i].push_back(ii(pos[j],num[j]));
        }
    }

    for(int i=1;i<=m;i++)
    {

        for(int j=0;j<adj[i].size();j++)
        {
            
            ii v=adj[i][j];

            tadj[v.first].push_back(ii(i,v.second));
        }
    }

    cout<<n<<" "<<m<<endl;

    for(int i=1;i<=n;i++)
    {
        cout<<tadj[i].size();

        for(int j=0;j<tadj[i].size();j++)
            cout<<" "<<tadj[i][j].first;
        cout<<endl;
        for(int j=0;j<tadj[i].size();j++)
        {
            cout<<tadj[i][j].second;
            if(j<tadj[i].size()-1)cout<<" ";
        }
        cout<<endl;

    }
    }
}
    




