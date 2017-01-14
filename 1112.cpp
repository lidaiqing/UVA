#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>

using namespace std;
int cost[105][105];
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int N,E,T;
        cin>>N>>E>>T;
        E--;
        int M;
        cin>>M;
        vector<int> link[N];
    
        for (int i = 0; i < M; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            a--,b--;
            link[b].push_back(a);
            cost[b][a] = c;
        }
        int dist[N];
        for (int i = 0; i < N; i++)
            dist[i] = 1000000;
        dist[E] = 0;
        priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
        
        pq.push(make_pair(0,E));
        
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
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (dist[i] <= T) cnt++;
        cout<<cnt<<endl;
        if (t != 0 )cout<<endl;
    }
}
