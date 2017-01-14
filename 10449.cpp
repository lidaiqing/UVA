#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;
vector<int> link[205];
bool neg_mark[205];
bool visit[205];
bool reach_mark[205];
void dfs_mark(int u)
{
    if (visit[u]) return;
    visit[u] = true;
    neg_mark[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        dfs_mark(v);
    }
}
void dfs_reach(int u )
{
    if (visit[u]) return;
    visit[u] = true;
    reach_mark[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        dfs_reach(v);
    }
}
int main()
{
    int n;
    int cnt = 0;
    while (scanf("%d",&n)==1)
    {
        cnt++;
        int node_value[n];
        for (int i = 0; i < n; i++)
            cin>>node_value[i];
        int r;
        cin>>r;
        memset(neg_mark,false,sizeof(neg_mark));
        memset(reach_mark,false,sizeof(reach_mark));
        for (int i = 0; i < n; i++)
            link[i].clear();
        for (int i = 0; i < r; i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            link[u].push_back(v);
           // link[v].push_back(u);
        }
        int cost[n][n];
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                cost[i][j] = (node_value[j] - node_value[i])*(node_value[j] - node_value[i])*(node_value[j] - node_value[i]);
                cost[j][i] = -cost[i][j];
            }
        }
        int dist[n];
        for (int i = 0; i < n; i++)
            dist[i] = (1<<30);
        dist[0] = 0;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < link[j].size(); k++)
                {
                    int u = j, v = link[j][k];
                    if (dist[u] + cost[u][v] < dist[v])
                        dist[v] = dist[u] + cost[u][v];
                }
            }
        }

        int q;
        cin>>q;
        cout<<"Set #"<<cnt<<endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < link[i].size(); j++){
                int v = link[i][j];
                if (dist[i] + cost[i][v] < dist[v]){
                    memset(visit,false,sizeof(visit));
                    dfs_mark(i);
                    memset(visit,false,sizeof(visit));
                    dfs_mark(v);
                    
                }
            }
        }
        memset(visit,false,sizeof(visit));
        dfs_reach(0);

        while (q--)
        {
            int u;
            cin>>u;
            u--;
            if (reach_mark[u] && !neg_mark[u] && u < n && dist[u] >= 3) cout<<dist[u]<<endl;
            else cout<<"?"<<endl;
            
        }
    }
}
            
            

