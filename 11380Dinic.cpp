#include <bits/stdc++.h>

using namespace std;

const int MAX = 3500;
const int HASH = 1000;
const int INF = 10000000;
int mf,f,s,t;
int res[MAX][MAX];
vector <int> p;
struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
	Edge &e = G[x][i];
	if (!dad[e.to] && e.cap - e.flow > 0) {
	  dad[e.to] = &G[x][i];
	  Q[tail++] = e.to;
	}
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	if (!e) { amt = 0; break; }
	amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	e->flow += amt;
	G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
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
        Dinic di(MAX);
        for (int i = 1; i <= X; i++)
        {
            for (int j = 1; j <= Y; j++)
            {
                int hash = i * 31 + j;
                if (mp[i][j] == '*')
                {
                    res[s][hash] = 1;
                    di.AddEdge(s,hash,1);
                }
                else if (mp[i][j] == '#')
                {
                    res[hash][t] = P;
                    di.AddEdge(hash,t,P);
                }
                if (mp[i][j] == '*' || mp[i][j] == '.')
                {
                    res[hash][hash+HASH] = 1;
                    di.AddEdge(hash,hash+HASH,1);
                }
                else if (mp[i][j] == '#' || mp[i][j] == '@')
                {
                    res[hash][hash+HASH] = INF;
                    di.AddEdge(hash,hash+HASH,INF);
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
                            di.AddEdge(hash+HASH,hash2,INF);
                        }
                    }
                }
            }
        }
        
                        
        mf = di.GetMaxFlow(s,t);
        cout<<mf<<endl;
        
    }
}

                                

                
        

        

