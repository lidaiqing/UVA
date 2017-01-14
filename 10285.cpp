#include <bits/stdc++.h>

using namespace std;
const int HASH = 100;
const int MAX = 20000;
vector<int> link[MAX];
vector<int> topList;
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
    int T;
    cin>>T;
    while (T--)
    {
        string name;
        cin>>name;
        int R,C;
        cin>>R>>C;
        int mp[R+1][C+1];
        int mx = 0;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cin>>mp[i][j];
                mx = max(mx,mp[i][j]);
            }
        }
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,-1,1};
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        topList.clear();
        memset(visit,false,sizeof(visit));
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                for (int k = 0; k < 4; k++) {
                    int rr = i + dr[k];
                    int cc = j + dc[k];
                    if (rr >= 1 && rr <= R && cc >= 1 && cc <= C)
                    {
                        if (mp[rr][cc] < mp[i][j]) {
                            link[i*HASH+j].push_back(rr*HASH+cc);
                        }
                    }
                }
            }
        }
        int dp[MAX];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
               if (!visit[i*HASH+j]) { 
                    //memset(visit,false,sizeof(visit));
                    //topList.clear();
                    dp[i*HASH+j] = 1;
                    top_sort(i*HASH+j);
                    /*for (int k = topList.size()-1; k >= 0; k--)
                    {
                        int u = topList[k];
                        for (int l = 0; l < link[u].size(); l++)
                        {
                            int v = link[u][l];
                            dp[v] = max(dp[v],dp[u] + 1);
                        }
                        ans = max(ans,dp[u]);
                    }*/
               }
            }
        }
    
        for (int i = topList.size()-1; i >= 0; i--)
        {
            int u = topList[i];
            for (int j = 0; j < link[u].size(); j++)
            {
                int v = link[u][j];
                dp[v] = max(dp[v], dp[u] + 1);
            }
            ans = max(dp[u],ans);
        }
        cout<<name<<": "<<ans<<endl;
    }
}
                        
        
        

