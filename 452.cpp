#include <bits/stdc++.h>

using namespace std;

vector<int> link[30];
vector<int> topList;
bool visit[30];
void top_sort(int u)
{
    if (visit[u]) return;
    visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];//cout<<v<<"asd"<<endl;
        top_sort(v);
    }
    topList.push_back(u);
}
    
int main()
{
    int T;
    cin>>T;
    string blank;
    cin.ignore();
    getline(cin,blank);
    while (T--)
    {
        string s;
        vector<int> in[30];
        int st;
        for (int i = 0; i < 27; i++)
            link[i].clear();
        
        int time[30];
        bool used[30];
        memset(used,false,sizeof(used));
        while (getline(cin,s))
        {
            if (s == "") break;
            istringstream ss(s);
            int u;
            int t;
            char c;
            ss>>c>>t;
            u = c - 'A';
            time[u] = -t;
            //cout<<u<<" "<<t<<endl;
            used[u] = true;
            while (ss >> c) {
                int v = c - 'A';
                used[v] = true;
                link[v].push_back(u);
                in[u].push_back(v);
            }
            
        }
        int ans = 0;
        for (int i = 0; i < 27; i++){
            if (used[i] && in[i].size() == 0){
                topList.clear();
                memset(visit,false,sizeof(visit));
                top_sort(i);
                int dp[30];
                memset(dp,0,sizeof(dp));
                for (int j = topList.size()-1; j >= 0; j--)
                {
                    int u = topList[j];
                   // cout<<j<<" "<<u<<endl;
                    dp[u] = min(dp[u],time[u]);
                    for (int k = 0; k < link[u].size(); k++)
                    {
                        int v = link[u][k];
                        dp[v] = min(dp[v], dp[u] + time[v]);
                    }
                    ans = min(ans,dp[u]);
                }
            }
        }
                
        cout<<-ans<<endl;
        if (T != 0) cout<<endl;
    }
}
            
        
        
        
        
