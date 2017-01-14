#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <set>
using namespace std;
struct node{
    int f,e;
};
class comp{
    public:
        bool operator() (const pair<int,node> &lhs, const pair<int,node> &rhs) const
        {
            return (lhs.first > rhs.first);
        }
};
int main()
{
    int n,k;
    while (cin>>n>>k)
    {
        vector<int> elevator[n];
        set<int> elevator_check[n];
        int T[n];
        for (int i = 0; i < n; i++)
            cin>>T[i];
        cin.ignore();
        string s;
        for (int i = 0; i < n; i++)
        {
            getline(cin,s);
            istringstream ss(s);
            int floor;
            while (ss>>floor)
            {
                elevator[i].push_back(floor);
                elevator_check[i].insert(floor);
            }
        }
        int dist[105][n];
        for (int i = 0; i < 105; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = 1000000;
        priority_queue <pair<int,node>, vector<pair<int,node> > ,comp > pq;
        for (int i = 0; i < n; i++)
            if (elevator[i][0] == 0) {
                dist[0][i] = 0;
                node temp;
                temp.f = 0;
                temp.e = i;
                pq.push(make_pair(0,temp));
            }
        int ans = -1;
        while (!pq.empty())
        {
            pair<int,node> front = pq.top();
            pq.pop();
            int d =front.first, f = front.second.f, e = front.second.e;
            //cout<<d<<" "<<f<<" "<<e<<endl;
            if (d > dist[f][e]) continue;
            if (f == k){
                if (ans != -1) ans = min(ans,dist[f][e]);
                else ans = dist[f][e];
            }
            for (int i = 0; i < elevator[e].size(); i++)
            {
                int ff = elevator[e][i];
                int cost = abs(f - ff) * T[e];
                if (cost + dist[f][e] < dist[ff][e]){
                    dist[ff][e] = cost + dist[f][e];
                    node temp;
                    temp.f = ff;
                    temp.e = e;
                    pq.push(make_pair(dist[ff][e],temp));
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (i != e){
                    if (elevator_check[i].count(f) != 0){
                        int cost = 60;
                        if (dist[f][e] + cost < dist[f][i]){
                            dist[f][i] = dist[f][e] + cost;
                            node temp;
                            temp.f = f;
                            temp.e = i;
                            pq.push(make_pair(dist[f][i],temp));
                        }
                    }
                }
            }
        }
        if (ans == -1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
}

                                    
                    

        
