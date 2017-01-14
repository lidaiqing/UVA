#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

int n,m;
vector <int> link[10005];
int dfs_num[10005], dfs_low[10005], dfs_parent[10005];
int dfs_cnt, dfs_root, dfs_children;
bool dfs_vex[10005];
bool color_visit[10005];

void dfs_arti_cnt(int u)
{
    dfs_num[u] = dfs_low[u] = dfs_cnt++;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        if (dfs_num[v] == -1){
            dfs_parent[v] = u;
            if (u == dfs_root) dfs_children++;
            
            dfs_arti_cnt (v);

            if (dfs_low[v] >= dfs_num[u]) dfs_vex[u] = true;
            dfs_low[u] = min (dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}
void dfs_color_fill(int u,int c)
{
    color_visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        if (!color_visit[v])
            dfs_color_fill(v,c);
    }
}
bool comp(pair<int,int> l, pair<int,int> r)
{
    if (l.second != r.second) return (l.second > r.second);
    else return (l.first < r.first);
}
int main()
{
    while (1)
    {
        cin>>n>>m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++)
            link[i].clear();
        while (1)
        {
            int a,b;
            cin>>a>>b;
            if (a == -1 && b == -1) break;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        memset (dfs_num,-1,sizeof(dfs_num));
        memset (dfs_low,-1,sizeof(dfs_low));
        memset (dfs_parent,-1,sizeof(dfs_parent));
        memset (dfs_vex,false,sizeof(dfs_vex));
        
        for (int i = 0; i < n; i++)
        {
            if (dfs_num[i] == -1)
            {
                dfs_root = i;
                dfs_children = 0;
                dfs_cnt = 0;
                dfs_arti_cnt(i);
                dfs_vex[dfs_root] = (dfs_children < 1);
            }
        }
        vector <pair<int,int> > ans;
        for (int i = 0; i < n; i++)
        {
            if (dfs_vex[i])
            {  
                int value = 0;
                memset(color_visit,false,sizeof(color_visit));
                color_visit[i] = true;
                for (int j = 0; j < n; j++)
                {
                    if (!color_visit[j]){
                        value++;
                        dfs_color_fill(j,value);
                    }
                }
                ans.push_back(make_pair(i,value));
              }
            else
            {
                ans.push_back(make_pair(i,1));
            }
        }
        sort(ans.begin(),ans.end(),comp);

        for (int i = 0; i < m; i++)
        {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
       // for (int i = 0; i < n; i++)
          //  cout<<i<<" "<<dfs_num[i]<<" "<<dfs_low[i]<<endl;
        cout<<endl;
    }
}
        

            
        

