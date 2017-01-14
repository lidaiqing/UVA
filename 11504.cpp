#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <set>
using namespace std;

vector <int> link[100005];
vector <int> in[100005];
bool visit[100005];
int dfs_num[100005], dfs_low[100005];
int dfs_cnt;
vector <int> S;
int ans;
void dfs_scc_cnt(int u)
{
    dfs_num[u] = dfs_low[u] = dfs_cnt++;
    S.push_back(u);
    visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i]; //cout<<v<<endl;
        if (dfs_num[v] == -1){
            dfs_scc_cnt(v);
        }
        if (visit[v]){//cout<<v<<" "<<u<<endl;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);}
    }
    if (dfs_num[u] == dfs_low[u])
    {
        bool flag = true;//cout<<dfs_num[u]<<" "<<dfs_low[u]<<endl;
        set <int> check;
        while (1)
        {
            int v = S.back();//cout<<v<<endl;
            S.pop_back();
            check.insert(v);
            visit[v] = false;
            if (u == v) break;
        }
        set<int> :: iterator it;
        for (it = check.begin(); it != check.end(); it++)
        {
            int v = *it;
            for (int j = 0; j < in[v].size(); j++)
            {
                int t = in[v][j]; 
                if (check.count(t) == 0){
               // cout<<v<<" "<<t<<endl;
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
            
        if (flag) ans++;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        for (int i = 0; i < n; i++)
        {
            link[i].clear();
            in[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            link[a].push_back(b);
            in[b].push_back(a);
        }
        memset(visit,false,sizeof(visit));
        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,-1,sizeof(dfs_low));
        S.clear();
        dfs_cnt = 0;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dfs_num[i] == -1)
                dfs_scc_cnt(i);
        }
        cout<<ans<<endl;
    }
}

        

