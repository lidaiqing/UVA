#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;

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
int main()
{
    int n,m;
    while (1) {
        cin>>n>>m;
        if (n == 0 && m == 0) break;
        vector <pair<int,ii > > edge_list;
        int total = 0, mst_cnt = 0;
        for (int i = 0; i < m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            total += w;
            edge_list.push_back(make_pair(w,make_pair(u,v)));
        }
        sort(edge_list.begin(),edge_list.end());
    
        UnionFind UF (n);
        bool visit[m];
        memset(visit,false,sizeof(visit));
        for (int i = 0; i < m; i++)
        {
            int u,v,w;
            u = edge_list[i].second.first;
            v = edge_list[i].second.second;
            w = edge_list[i].first;
            if (!UF.isSameSet(u,v)){
                mst_cnt += w;
                visit[i] = true;
            }
            UF.UnionSet(u,v);
        }
        vi ans;
        for (int i = 0; i < m; i++)
            if (!visit[i]) ans.push_back(edge_list[i].first);
        if (total == mst_cnt) 
            cout <<"forest"<<endl;
        else {
            //cout<<total - mst_cnt<<endl;
            sort(ans.begin(),ans.end());
            for (int i = 0; i < ans.size()-1; i++)
                cout<<ans[i]<<" ";
            cout<<ans.back()<<endl;
        }
    }
}
