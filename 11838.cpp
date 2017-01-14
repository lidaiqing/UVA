#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;
vector <int> link[2005];
bool visit[2005];
int dfs_low[2005],dfs_num[2005],dfs_cnt;
bool flag;
vector <int> S;
int n,m;
void dfs_scc_check(int u)
{
    dfs_num[u] = dfs_low[u] = dfs_cnt++;
    S.push_back(u);
    visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        if (dfs_num[v] == -1)
            dfs_scc_check(v);
        if (visit[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u])
    {
        int cnt = 0;//cout<<u<<endl;
        while(1){
            cnt++;
            int v = S.back();
            S.pop_back();
            visit[v] = false;
            if (u == v) break;
        }
        if (cnt  == n){
            flag = true;
        }
    }
}
int main()
{
    
    while (1)
    {
        cin>>n>>m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++)
            link[i].clear();
        for (int i = 0; i < m; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            a--,b--;
            link[a].push_back(b);
            if (c == 2)
                link[b].push_back(a);
        }
        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,-1,sizeof(dfs_low));
        memset(visit,false,sizeof(visit));
        S.clear();
        flag = false;
        dfs_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (dfs_num[i] == -1)
                dfs_scc_check(i);
        }
        if (flag) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
}
        

