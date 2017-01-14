#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;
vector <int> link[105];
int dfs_cnt, dfs_root, root_children;
int dfs_num[105], dfs_low[105], dfs_parent[105];
bool articulation_v[105];

void arti_find(int u)
{
    dfs_low[u] = dfs_cnt;
    dfs_num[u] = dfs_cnt;
    dfs_cnt++;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        if (dfs_num[v] == -1)
        {
            dfs_parent[v] = u;
            if (u == dfs_root) root_children++;

            arti_find(v);

            if (dfs_low[v] >= dfs_num[u])
                articulation_v[u] = true;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main()
{
    while(1)
    {
        int N;
        cin>>N;
        if (N == 0) break;
        for (int i = 1; i <= N; i++)
            link[i].clear();
        cin.ignore();
        while(1)
        {
            string s;
            getline(cin,s);
            int a,b;
            stringstream ss;
            ss.str(s);
            ss >> a;
            if (a == 0) break;
            while(ss >> b)
            {
                link[a].push_back(b);
                link[b].push_back(a);
            }
        }
        dfs_cnt = 0;
        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,-1,sizeof(dfs_low));
        memset(dfs_parent,-1,sizeof(dfs_parent));
        memset(articulation_v,false,sizeof(articulation_v));
        for (int i = 1; i <= N; i++)
        {
            if (dfs_num[i] == -1)
            {
                dfs_root = i;
                root_children = 0;
                arti_find(i);
                articulation_v[i] = (root_children > 1);
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++)
            if (articulation_v[i]) ans++;
        cout<<ans<<endl;
    }
}



            

