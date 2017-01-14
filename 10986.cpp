#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <queue>
#include <functional>

using namespace std;
int cost[20000][20000];
int main()
{
    int N;
    cin>>N;
    int cnt = 0;
    while (N--)
    {
        cnt++;
        int n,m,S,T;
        cin>>n>>m>>S>>T;
        vector<int> link[n];
        for (int i = 0; i < m; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            link[a].push_back(b);
            link[b].push_back(a);
            cost[a][b] = c;
            cost[b][a] = c;
        }
        int dist[n];
        for (int i = 0; i < n; i++)
            dist[i] = 1000000;
        dist[S] = 0;
        priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
        pq.push(make_pair(0,S));
        while (!pq.empty())
        {
            pair<int,int> front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;
            for (int i = 0; i < link[u].size(); i++)
            {
                int v = link[u][i];
                if (dist[u] + cost[u][v] < dist[v]){
                    dist[v] = dist[u] + cost[u][v];
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        cout<<"Case #"<<cnt<<": ";
        if (dist[T] == 1000000) cout<<"unreachable"<<endl;
        else cout<<dist[T]<<endl;
    }
}
