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
int main()
{

    int m,n;
    while(1) {
        cin>>m>>n;
        if (m == 0 && n == 0) break;
        vector <pair<int, pair<int, int> > > edge_list;
        int total_length = 0;
        for (int i = 0; i < n; i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            total_length += z;
            edge_list.push_back(make_pair(z, make_pair(x,y) ));
        }
        sort(edge_list.begin(),edge_list.end());
        int mst_cnt = 0;
        
        UnionFind UF (m);
        
        for (int i = 0; i < n; i++)
        {
            if (!UF.isSameSet(edge_list[i].second.first,edge_list[i].second.second))
            {
                mst_cnt += edge_list[i].first;
                UF.UnionSet(edge_list[i].second.first,edge_list[i].second.second);
            }
        }
        int ans = total_length - mst_cnt;
        cout<<ans<<endl;
    }
}
            
