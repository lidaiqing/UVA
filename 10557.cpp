#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;
vector<int> link[105];
bool visit[105];
bool reach_mark[105];
bool pos_mark[105];
void dfs_reach(int u)
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
void dfs_pos_mark(int u)
{
    if (visit[u]) return;
    visit[u] = true;
    pos_mark[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        dfs_pos_mark(v);
    }
}

int main()
{
    int n;
    while (1)
    {
        cin>>n;
        if (n == -1) break;
        int cost[n];
        for (int i = 0; i < n; i++)
            link[i].clear();
        for (int i = 0; i < n; i++)
        {
            cin>>cost[i];
            int m;
            cin>>m;
            for (int j = 0; j < m; j++)
            {
                int v;
                cin>>v;
                v--;
                link[i].push_back(v);
            }
        }
        int dist[n];
        for (int i = 0; i < n; i++)
            dist[i] = -1000000;
        memset(pos_mark,false,sizeof(pos_mark));
        memset(reach_mark,false,sizeof(reach_mark));
        dist[0] = 100;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < link[j].size(); k++)
                {
                    int u = j, v = link[j][k];
                    if (dist[u] + cost[v] > dist[v] && dist[u] + cost[v] > 0){
                        dist[v] = dist[u] + cost[v];
                       // cout<<u<<" "<<v<<" "<<dist[v]<<endl;
                    }
                }
            }
        }
        memset(visit,false,sizeof(visit));
        dfs_reach(0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < link[i].size(); j++)
            {
                int u = i, v = link[i][j];
                if (dist[u] + cost[v] > dist[v] && dist[u] + cost[v] > 0){
                   // cout<<u<<" "<<v<<"asd"<<endl;
                    memset(visit,false,sizeof(visit));
                    dfs_pos_mark(u);
                    memset(visit,false,sizeof(visit));
                    dfs_pos_mark(v);
                }
            }
        }
        if (reach_mark[n-1]){
            if (pos_mark[n-1]) cout<<"winnable"<<endl;
            else if (dist[n-1] > 0) cout<<"winnable"<<endl;
            else cout<<"hopeless"<<endl;
        }
        else cout<<"hopeless"<<endl;
    }
}
        
        
        

