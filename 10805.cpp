#include <bits/stdc++.h>

using namespace std;
const int MAX = 26;
const int INF = 100000000;
vector<int> link[MAX];
bool visit[MAX];
int mx;
vector<int> bfs_tree[MAX];
int x;

void dfs(int u, int len)
{
    if (visit[u]) return;
    visit[u] = true;
    if (mx < len)
    {
        mx = len;
        x = u;
    }
    for (int i = 0; i < bfs_tree[u].size(); i++)
    {
        int v = bfs_tree[u][i];
        dfs(v,len+1);
    }
}
int find_diameter(int u)
{
    for (int i = 0; i < MAX; i++)
        bfs_tree[i].clear();
    int leaf, root = u;
    queue<int> q;
    q.push(root);
    memset(visit,false,sizeof(visit));
    visit[root] = true;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int i = 0; i < link[top].size(); i++)
        {
            int v = link[top][i];
            if (!visit[v])
            {
                bfs_tree[top].push_back(v);
                bfs_tree[v].push_back(top);
                q.push(v);
                visit[v] = true;
            }
        }
        leaf = top;
    }
    memset(visit,false,sizeof(visit));
    mx = -1;
    dfs(leaf,0);
    memset(visit,false,sizeof(visit));
    mx = -1;
    dfs(x,0);
    cout<<u<<" "<<leaf<<" "<<x<<" "<<mx<<" "<<endl;
    
    return mx;
}
    
int main()
{
    int N;
    cin>>N;
    int cnt = 0;
    while (N--)
    {
        cnt++;
        int n, m;
        cin>>n>>m;
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        
        int min_diameter = INF;
        
        for (int i = 0; i < n; i++)
        {
            min_diameter = min(min_diameter,find_diameter(i));
        }
        cout<<"Case #"<<cnt<<":"<<endl;
        cout<<min_diameter<<endl;
        cout<<endl;
    }
}

