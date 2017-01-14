#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <utility>
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
struct node{
    int x,y;
};
double dist_cnt (int x,int y,int xx, int yy)
{
    return( (double)sqrt( (x-xx)*(x-xx) + (y-yy)*(y-yy)));
}

int main()
{
    int N;
    cin>>N;
    while (N--)
    {
        int S,P;
        cin>>S>>P;
        node vtx[P];
        for (int i = 0; i < P; i++)
        {
            cin>>vtx[i].x>>vtx[i].y;
        }
        vector <pair<double, pair<int,int> > > edge_list;
        
        for (int i = 0; i < P; i++) {
            for (int j = i+1; j < P; j++) {
                
                double w = dist_cnt(vtx[i].x,vtx[i].y,vtx[j].x,vtx[j].y);
                edge_list.push_back(make_pair(w,make_pair(i,j)));
            }
        }
        sort(edge_list.begin(),edge_list.end());
        
        UnionFind UF (P);
        double ans;
        int key = (P-1) - S + 1 ;
        int cnt = 0;
        for (int i = 0; i < edge_list.size(); i++)
        {
            int u,v;
            double w;
            u = edge_list[i].second.first;
            v = edge_list[i].second.second;
            w = edge_list[i].first;
            if (!UF.isSameSet(u,v)){
                UF.UnionSet(u,v);
                cnt++;
                if (cnt == key){
                    ans = w;
                    break;
                }
            }
        }
        
    
    
        printf("%0.2f\n",ans);
    }
}

