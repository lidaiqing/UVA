#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
class UnionFind {
    private: vector<int> p, rank;
    public:
        UnionFind(int N) {
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i < N; i++)
                p[i] = i;
        }
        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet (int i, int j) {
            return findSet(i) == findSet(j);
        }
        void UnionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y]) p[y] = x;
                else {
                    p[x] = y;
                    if (rank[x] == rank[y])
                        rank[y] ++;
                }
            }
        }
};
vector<int> link[105];
bool visit[105];
int weight[105][105];
int ans;
int parent[105];
int c,s,q;

void dfs_travl (int u, int st, int end)
{
    visit[u] = true;
    if (u == end){ 
        for (int i = u; i != st; i = parent[i])
        {
           // cout << i << endl;
            ans = max(ans,weight[i][parent[i]]);
        }
        return;
    }
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        if (!visit[v])
        {
            parent[v] = u;
            dfs_travl(v,st,end);
        }
    }
}
typedef vector<int> vi;
typedef pair<int,int> ii;
int main()
{
    int cnt = 0;
    while (1) {
        cnt++;
        cin>>c>>s>>q;
        if (c == 0 && s == 0 && q == 0) break;
        if (cnt != 1) cout<<endl;
        vector<pair<int, ii> > edge_list;
        for (int i = 0; i < c; i++)
            link[i].clear();
        for (int i = 0; i < s; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            weight[u][v] = w;
            weight[v][u] = w;
            edge_list.push_back(make_pair(w,make_pair(u,v)));
        }

        sort(edge_list.begin(),edge_list.end());
        UnionFind UF (c);
        for (int i = 0; i < s; i++)
        {
            int u ,v ,w;
            u = edge_list[i].second.first;
            v = edge_list[i].second.second;
            w = edge_list[i].first;
            if (!UF.isSameSet(u,v))
            {
                UF.UnionSet(u,v);
                link[u].push_back(v);
                link[v].push_back(u);
            }
        }
        cout<<"Case #"<<cnt<<endl;
        for (int i = 0; i < q; i++)
        {
            int c1,c2;
            cin>>c1>>c2;
            c1--,c2--;
            memset(parent,-1,sizeof(parent));
            ans = -1;
            memset(visit,false,sizeof(visit));
            dfs_travl(c1,c1,c2);
           if (ans != -1) cout<<ans<<endl;
           else cout<<"no path"<<endl;
        }
    }
}
