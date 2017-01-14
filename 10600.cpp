#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>

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
int N,M;

bool check (UnionFind UF,int i,int j)
{
    if (!UF.isSameSet(i,j)) return false;

    return true;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        vector <pair<int,pair<int,int> > > edge_list;
        for (int i = 0; i < M; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            a--,b--;
            edge_list.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(edge_list.begin(),edge_list.end());
        
        bool mst_edge[M];
        memset(mst_edge,false,sizeof(mst_edge));

        UnionFind UF (N);
        int most_min = 0 ,sec_min = 1000000;
        for (int i = 0; i < M; i++)
        {
            int u,v,w;
            u = edge_list[i].second.first;
            v = edge_list[i].second.second;
            w = edge_list[i].first;
            if (!UF.isSameSet(u,v)){
                most_min += w;
                UF.UnionSet(u,v);
                mst_edge[i] = true;
            }
        }
        for (int i = 0; i < M; i++)
        {
            if (mst_edge[i]){
                UnionFind new_UF (N);
                int sec_cnt = 0;
                for (int j = 0; j < M; j++)
                {
                    int u,v,w;
                    u = edge_list[j].second.first;
                    v = edge_list[j].second.second;
                    w = edge_list[j].first;

                    if (j != i && !new_UF.isSameSet(u,v)){
                        sec_cnt += w;
                        new_UF.UnionSet(u,v);
                    }
                }
               if (check(new_UF,edge_list[i].second.first,edge_list[i].second.second)) sec_min = min (sec_min,sec_cnt);
            }
        }
        cout<<most_min<<" "<<sec_min<<endl;
    }
}
