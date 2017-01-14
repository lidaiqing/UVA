#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;
vector <int> link[105];
vector <int> ans;
bool visit[105];
void dfs_top(int u)
{
    visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        if (!visit[link[u][i]]) dfs_top(link[u][i]);
    }
    ans.push_back(u);
}
int main()
{
    while(1)
    {
        int n, m;
        cin>>n>>m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i <= n; i++)
            link[i].clear();
        ans.clear();
        memset(visit,false,sizeof(visit));
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            link[a].push_back(b);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
                dfs_top(i);
        }
        
        for (int i = ans.size()-1; i > 0; i--)
            cout<<ans[i]<<" ";
        cout<<ans[0]<<endl;
    }
}
