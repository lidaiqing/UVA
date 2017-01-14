#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000000;
const int SIZE = 3000;
const int MAX = 500007;
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

int main()
{
    int Case = 0;
    while (1)
    {
        int n,m;
        cin>>n;
        if (n == 0) break;
        cin>>m;
        Case++;
        Dinic di(MAX);
        long long cnt = 0;
        int s = SIZE + 100 + 1, t = SIZE + 100 + 2;
        vector<pair<int, pair<int,int> > > monkey;
        bool timeSet[MAX+5];
        memset(timeSet,false,sizeof(timeSet));
        for (int i = 1; i <= n; i++)
        {
            int v,a,b;
            cin>>v>>a>>b;
            cnt += v;
            timeSet[a] = true;
            timeSet[b] = true;
            monkey.push_back(make_pair(v,make_pair(a,b)));
            int ind = SIZE + i;
            di.AddEdge(s,ind,v);
        }
        int st,end;
        int num = 0;
        int prev = -1;
        vector<pair<int,pair<int,int> > >interval;
        for (int i = 0; i <= MAX; i++)
        {
            if (timeSet[i]){
        
            if (prev == -1){
                prev = i;
            }
            else {
            
                    st = prev;
                    end = i;
                    interval.push_back(make_pair(st,make_pair(st,end)));
                    for (int k = 0; k < monkey.size(); k++) {
                        int mst = monkey[k].second.first;
                        int mend = monkey[k].second.second;
                        //cout<<"asd"<<mst<<" "<<mend<<" "<<st<<" "<<end<<endl;
                        if ((mst >= st && mst <= end) || (mend >= st && mend <= end)) {
                            int ind = SIZE + k + 1;
                            int cap;
                            if (mst >= st && mend <= end) cap = mend - mst;
                            else if (mst < st) cap = mend - st;
                            else if (mend > end) cap = end - mst;
                           // cout<<k<<" "<<mst<<" "<<mend<<" "<<st<<" "<<end<<" "<<num<<" "<<cap<<endl;
                            di.AddEdge(ind,num,cap);
                        }
                        else if (mst < st && mend > end) {
                            int cap = end - st;
                            int ind = SIZE + k + 1;
                            di.AddEdge(ind,num,cap);
                        }
                    }
                    di.AddEdge(num,t,m*(end-st));
                   // cout<<num<<" "<<(end-st)*m<<endl;
                    prev = i;
                    num++;
                }
            }
        }
                            
        
        long long ans = di.GetMaxFlow(s,t);

        cout<<"Case "<<Case<<": ";
       // cout<<ans<<" "<<cnt<<endl;
        if (ans != cnt) cout<<"No"<<endl;
        else {
            cout<<"Yes"<<endl;

            for (int i = 1; i <= n; i++)
            {
                int ind = SIZE + i;
                vector<pair<int ,int> > v;
                for (int j = 0; j < di.G[ind].size(); j++)
                {
                    int jj = di.G[ind][j].to;
                    //cout<<"asdas"<<endl;
                    //cout<<i<<" "<<j<<" "<<interval[jj].first<<" "<<interval[jj].second<<" "<<di.G[ind][j].flow<<endl;
                    
                    if (di.G[ind][j].flow > 0) {
                        int total = interval[jj].second.second - interval[jj].second.first;
                        int len = di.G[ind][j].flow;
                        //cout<<interval[j].first<<" "<<interval[j].second<<" "<<total<<" "<<len<<endl;
                        if (len == total) {
                            v.push_back(make_pair(interval[jj].second.first,interval[jj].second.second));
                        }
                        else if (len < total) {
                            v.push_back(make_pair(interval[jj].second.first,interval[jj].second.first+len));
                            interval[jj].second.first += len;
                        }
                        else {
                            v.push_back(make_pair(interval[jj].second.first,interval[jj].second.second));
                            len -= total;
                            interval[jj].second.first = interval[jj].first;
                            v.push_back(make_pair(interval[jj].second.first,interval[jj].second.first+len));
                            interval[jj].second.first += len;
                        }
                        
                        
                    }
                }
                sort(v.begin(),v.end());
                vector<pair<int,int> > ans;
                int st, end;
                if (v.size() != 0){
                    st = v[0].first;
                    end = v[0].second;
                }
                if (v.size() == 1) ans.push_back(make_pair(st,end));
                for (int j = 1; j < v.size(); j++)
                {
                    if (v[j].first == end)
                    {
                        end = v[j].second;
                    }
                    else 
                    {
                        ans.push_back(make_pair(st,end));
                        st = v[j].first;
                        end = v[j].second;
                    }
                    if (j == v.size() - 1)
                        ans.push_back(make_pair(st,end));
                }
                                      
                    
                
                if (ans.size() != 0) cout<<ans.size();
                for (int j = 0; j < ans.size(); j++)
                {
                    cout<<" ("<<ans[j].first<<","<<ans[j].second<<")";
                }
                if (ans.size() != 0) cout<<endl;
            }
        }
    }
}

                
        
            

