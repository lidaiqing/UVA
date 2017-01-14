#include <bits/stdc++.h>

using namespace std;
const int MAX = 20000;
const int HASH = 121;
const int INF = 1000000000;
vector<int> link[MAX];
vector<int> topList;
bool visit[MAX];
int Time[MAX][MAX];
void top_sort(int u)
{
    if (visit[u]) return;
    visit[u] = true;
    for (int i = 0 ; i < link[u].size(); i++)
    {
        int v = link[u][i];
        top_sort(v);
    }
    topList.push_back(u);
}
int dp[MAX];
int main()
{
    
    string name;
    while (cin>>name)
    {
        int n,m;
        cin>>n>>m;
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        topList.clear();
        for (int i = 0; i < MAX; i++)
            dp[i] = INF;
        for (int i = 1; i <= m; i++)
            dp[i] = 0;
        for (int k = 0; k < n - 1; k++) {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= m; j++) {
                    int hash1 = k * HASH + i;
                    int hash2 = (k + 1) * HASH + j;
                    cin>>Time[hash1][hash2];
                    link[hash1].push_back(hash2);
                }
            }
        }
        memset(visit,false,sizeof(visit));
        for (int i = 1; i <= m; i++)
        {
            if (!visit[i])
                top_sort(i);
        }
        
        int ans = INF;
        for (int i = topList.size()-1; i >= 0; i--)
        {
            int u = topList[i];

            for (int j = 0; j < link[u].size(); j++)
            {
                int v = link[u][j];
                dp[v] = min(dp[v],dp[u] + Time[u][v] + 2);
               // cout<<u<<" "<<v<<" "<<dp[v]<<endl;
            }
            if (u >= (n-1) * HASH) ans = min(ans,dp[u]);
        }
        cout<<name<<endl;
        cout<<ans<<endl;
    }
}
        
        
                    
