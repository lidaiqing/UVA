#include <bits/stdc++.h>

using namespace std;
const int MAX = 205;
vector<int> link[MAX];
bool visit[MAX];
void connecty_check(int u)
{
    if (visit[u]) return;
    visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        connecty_check(v);
    }
}
int main()
{
    int N,R;
    while (cin>>N)
    {
        cin>>R;
        int degree[N];
        bool check[N];
        int st;
        memset(check,0,sizeof(check));
        memset(degree,0,sizeof(degree));
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        memset(visit,false,sizeof(visit));
        for (int i = 0; i < R; i++)
        {
            int u,v;
            cin>>u>>v;
            st = u;
            link[u].push_back(v);
            check[u] = true;
            check[v] = true;
            degree[u]++;
            degree[v]++;
        }
        bool flag = false;
        for (int i = 0; i < N; i++)
            if (degree[i] % 2 != 0 || degree[i] == 0)
            {
                flag = true;
                break;
            }
        
        if (flag) cout<<"Not Possible"<<endl;
        else {
            cout<<"Possible"<<endl;
        }
    }
}
