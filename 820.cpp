#include <bits/stdc++.h>

using namespace std;

const int MAX = 2005;
const int INF = 10000000;

int res[MAX][MAX], mf,f,s,t;
vector<int> p;

void augment(int v, int minEdge)
{
    if (v == s) {
        f = minEdge;
        return;
    }
    else if (p[v] != -1) {
        augment(p[v], min(minEdge,res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main()
{
    int cnt = 0;
    while (1)
    {
        cnt++;
        int n;
        cin>>n;
        if (n == 0) break;
        mf = 0;
        cin>>s>>t;
        int c;
        cin>>c;
        memset(res,0,sizeof(res));
        int newv = n+1;
        for (int i = 0; i < c; i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            if (res[a][b] != 0) res[a][b] += w;
            else res[a][b] = w;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && res[i][j] != 0)
                {
                    res[j][newv] = res[i][j];
                    res[newv][i] = res[i][j];
                    newv++;
                }
            }
        }
                    
        while (1)
        {
            f = 0;
            vector<int> dist(MAX,INF);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(MAX,-1);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (u == t) break;
                for (int v = 1; v < MAX; v++)
                {
                    if (res[u][v] > 0 && dist[v] == INF)
                    {
                        q.push(v);
                        dist[v] = dist[u] + 1;
                        p[v] = u;
                    }
                }
            }
            augment(t,INF);
            if (f == 0) break;
            mf += f;
        }
        cout<<"Network "<<cnt<<endl;
        cout<<"The bandwidth is "<<mf<<"."<<endl;
        cout<<endl;
    }
}
            
