#include <bits/stdc++.h>

using namespace std;

const int MAX = 3500;
const int HASH = 1000;
const int INF = 10000000;
int mf,f,s,t;
int res[MAX][MAX];
vector <int> p;
struct node{
    int x,y;
};
void augment(int v,int minEdge)
{
    if (v == s) {
        f = minEdge;
        return;
    }else if (p[v] != -1){
    augment(p[v],min(minEdge,res[p[v]][v]));
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
    }
}
void Edmonds_Karp()
{
    while (1)
    {
        f = 0;
        p.assign(MAX,-1);
        vector<int> dist(MAX,INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == t) break;
            for (int i = 1; i < MAX; i++)
            {
                if (res[u][i] > 0 && dist[i] == INF)
                {
                    dist[i] = dist[u] + 1;
                    p[i] = u;
                    q.push(i);
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
    int X;
    while (cin>>X)
    {
        int Y, P;
        cin>>Y>>P;
        char mp[X+1][Y+1];
        for (int i = 1; i <= X; i++)
        {
            for (int j = 1; j <= Y; j++)
            {
                cin>>mp[i][j];
            }
        }
        memset(res,0,sizeof(res));
        s = MAX-2, t = MAX-1;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        for (int i = 1; i <= X; i++)
        {
            for (int j = 1; j <= Y; j++)
            {
                int hash = i * 31 + j;
                if (mp[i][j] == '*')
                    res[s][hash] = 1;
                else if (mp[i][j] == '#')
                    res[hash][t] = P;
                if (mp[i][j] == '*' || mp[i][j] == '.')
                {
                    res[hash][hash+HASH] = 1;
                }
                else if (mp[i][j] == '#' || mp[i][j] == '@')
                {
                    res[hash][hash+HASH] = INF;
                }
                for (int k = 0; k < 4; k++)
                {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (xx >= 1 && xx <= X && yy >= 1 && yy <= Y)
                    {
                        if (mp[i][j] != '~' && mp[xx][yy] != '~')
                        {
                            int hash2 = xx * 31 + yy;
                            res[hash+HASH][hash2] = INF;
                        }
                    }
                }
            }
        }
                        
        mf = 0;
        Edmonds_Karp();
        cout<<mf<<endl;
        
    }
}

                                

                
        

        
