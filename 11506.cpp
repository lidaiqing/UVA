#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000;
const int INF = 10000000;
const int HASH = 1000;
const int NEW = 500;
int mf,f,s,t;
int res[MAX][MAX];
vector<int> p;

void augment(int v, int minEdge)
{
    if (v == s) {
        f = minEdge;
        return;
    }
    else if (p[v] != -1)
    {
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void Edmond_Krap()
{
    while (1)
    {
        f = 0;
        p.assign(MAX,-1);
        vector<int> dist(MAX,INF);
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == t) break;
            for (int v = 1; v <= MAX; v++)
            {
                if (res[u][v] > 0 && dist[v] == INF)
                {
                    dist[v] = dist[u] + 1;
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        augment(t,INF);
        if (f == 0) break;
        mf += f;
    }
}

int main()
{
    while (1)
    {
        mf = 0;
        int M,W;
        cin>>M>>W;
        if (M == 0 && W == 0) break;
        s = 1, t = M;
        memset(res,0,sizeof(res));
        for (int i = 0; i < M-2; i++)
        {
            int ind, c;
            cin>>ind>>c;
            res[ind][ind+HASH] = c;
        }
        for (int i = 0; i < W; i++)
        {
            int j,k;
            cin>>j>>k;
            int d;
            cin>>d;
            if (j == 1) res[j][k] = d;
            else {
                res[j+HASH][k] = d;
                res[k+HASH][j] = d;
            }
        }
        Edmond_Krap();
        cout<<mf<<endl;
    }
}
        
            

