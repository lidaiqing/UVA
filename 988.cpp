#include <bits/stdc++.h>

using namespace std;
const int MAX = 10000;
vector <int> link[MAX];
vector <int> topList;
bool visit[MAX];
void top_sort(int u)
{
    if (visit[u]) return;
    visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        top_sort(v);
    }
    topList.push_back(u);
}
int main()
{
    int n;
    bool first = true;
    while (cin>>n)
    {
        if (first) {
            first = false;
        }
        else cout<<endl;
        topList.clear();
        for (int i = 0; i < MAX; i++)
            link[i].clear();

        for (int i = 0; i < n; i++)
        {
            int m;
            cin>>m;
            for (int j = 0; j < m; j++)
            {
                int v;
                cin>>v;
                link[i].push_back(v);
            }
        }
        long long dp[MAX];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        memset(visit,false,sizeof(visit));
        top_sort(0);
        for (int i = topList.size()-1; i >= 0; i--)
        {
            int u = topList[i];
            for (int j = 0; j < link[u].size(); j++)
            {
                int v = link[u][j];
                dp[v] += dp[u];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
            if (link[i].size() == 0)
                ans += dp[i];
        cout<<ans<<endl;
    }
}
