#include <bits/stdc++.h>

using namespace std;
const int MAX = 5050;
const int INF = 1000000000;
vector<int> link[MAX];
bool visit[MAX];
int y;
int x;
int dist[MAX];
int mx;
void dfs_find_x(int u, int len)
{
    if (visit[u]) return;
    visit[u] = true;
    dist[u] = max(dist[u],len);
    if (mx < len){
           mx = len;
           x = u; 
    }
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
         dfs_find_x(v,len+1);
    }

}
void dfs_find_y(int u, int len)
{
    if (visit[u]) return;
    visit[u] = true;
    dist[u] = max(dist[u],len);
    if (len > mx) {
            mx = len;
            y = u;
    }
   for (int i = 0; i < link[u].size(); i++)
        {
            int v = link[u][i];
            dfs_find_y(v,len+1);
        }
}
void dfs(int u, int len)
{
    if (visit[u]) return;
    visit[u] = true;
    dist[u] = max(dist[u],len);
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        dfs(v,len+1);
    }
}

int main()
{
    int N;
    while (cin>>N)
    {
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        for (int i = 1; i <= N; i++)
        {
            int K;
            cin>>K;
            for (int j = 1; j <= K; j++)
            {
                int v;
                cin>>v;
                link[i].push_back(v);
                link[v].push_back(i);
            }
        }
        memset(dist,0,sizeof(dist));
        mx = -1;
        memset(visit,false,sizeof(visit));
        dfs_find_x(1,0);
        memset(visit,false,sizeof(visit));
        mx = 0;
        dfs_find_y(x,0);
        memset(visit,false,sizeof(visit));
        dfs(x,0);
        memset(visit,false,sizeof(visit));
        dfs(y,0);
       // cout<<x<<" "<<y<<endl;
        vector<int> s;
        vector<int> l;
        int shortest = INF;
        int longest = -1;
        for (int i = 1; i <= N; i++)
        {
            shortest = min(shortest,dist[i]);
            longest = max(longest,dist[i]);
        }
        for (int i = 1; i <= N; i++)
        {
            int len = dist[i];
            if (len == shortest) s.push_back(i);
            if (len == longest) l.push_back(i);
        }
        sort(s.begin(),s.end());
        sort(l.begin(),l.end());
        cout<<"Best Roots  :";
        for (int i = 0; i < s.size(); i++)
            cout<<" "<<s[i];
        cout<<endl;
        cout<<"Worst Roots :";
        for (int i = 0; i < l.size(); i++)
            cout<<" "<<l[i];
        cout<<endl;
    }
}

