#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000;
const int HASH = 300;
const int MAX = 1000;
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
double dist(int x1,int y1, int x2, int y2)
{
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}
struct node{
    int x,y,n,m;
};
const double ep = 0.00001;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int N;
        double D;
        cin>>N>>D;
        Dinic di(MAX);
        node Node[N+1];
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            int x,y,n,m;
            cin>>Node[i].x>>Node[i].y>>Node[i].n>>Node[i].m;
            cnt += Node[i].n;
            if (Node[i].n != 0) di.AddEdge(0,i,Node[i].n);
            di.AddEdge(i,i+HASH,Node[i].m);
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (i != j)
                {
                    if (dist(Node[i].x,Node[i].y,Node[j].x,Node[j].y) <= D )
                    {
                        //cout<<i<<" "<<j<<endl;
                        di.AddEdge(i+HASH,j,INF);
                        di.AddEdge(j+HASH,i,INF);
                    }
                }
            }
        }
        bool flag = false;
        vector <int> ans;
        for (int i = 1; i <= N; i++)
        {
            Dinic temp = di;
            int mf = temp.GetMaxFlow(0,i);
           // cout<<i<<" "<<mf<<endl;
            if (mf == cnt){
                flag = true;
                ans.push_back(i-1);
            }
        }
        if (flag) {
            for (int i = 0; i < ans.size()-1; i++)
                cout<<ans[i]<<" ";
            cout<<ans.back()<<endl;
        }
        if (!flag) cout<<"-1"<<endl;
    }
}
        
            
        
    

