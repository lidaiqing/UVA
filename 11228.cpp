#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <utility>
#include <math.h>
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
double dist_cnt (int x,int y, int xx, int yy)
{
    return (double) (sqrt( (x-xx)*(x-xx) + (y-yy)*(y-yy)));
}
bool comp (pair<double,pair<int,int> > l, pair<double,pair<int,int> > r)
{
    return (l.first < r.first);
}
int main()
{
    int t;
    cin>>t;
    int cnt = 0;
    while (t--)
    {
        cnt++;
        int n, r;
        cin>>n>>r;
        vector <pair<double,pair<int,int> > > edge_list;
        node vtx[n];
        for (int i = 0; i < n; i++)
        {
            cin>>vtx[i].x>>vtx[i].y;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (i != j){
                    double w;
                    w = dist_cnt(vtx[i].x,vtx[i].y,vtx[j].x,vtx[j].y);
                    edge_list.push_back(make_pair(w, make_pair(i,j)));
                }
            }
        }
        sort(edge_list.begin(), edge_list.end(),comp);
       // for (int i = 0; i < edge_list.size(); i++)
        //    cout<<edge_list[i].first<<" "<<edge_list[i].second.first<<endl;
        double mst_road_cost = 0, mst_rail_cost = 0;
        int num_state = 1;
        UnionFind UF(n);
        for (int i = 0; i < edge_list.size(); i++) {
            pair <double, pair<int,int> > front = edge_list[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                if (front.first >= r) {
                    num_state++;
                    mst_rail_cost += front.first;
                }
                else {
                    mst_road_cost += front.first;
                }
                UF.UnionSet(front.second.first, front.second.second);
            }
        }
        cout<<"Case #"<<cnt<<": "<<num_state<<" "<<round(mst_road_cost)<<" "<<round(mst_rail_cost)<<endl;
    }
}
