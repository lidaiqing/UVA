#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
int cost_s[10005][10005];
int cost_e[10005][10005];
int main()
{
    int T;

    scanf("%d",&T);
    while (T--)
    {
        int N,M,s,t,p;
        scanf("%d%d%d%d%d",&N,&M,&s,&t,&p);
        s--,t--;
        vector<int> link_s[N];
        vector<int> link_e[N];
        
        for (int i = 0; i < M; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            u--,v--;
            link_s[u].push_back(v);
            link_e[v].push_back(u);
            cost_s[u][v] = c;
            cost_e[v][u] = c;
        }
        int dist_s[N];
        for (int i = 0; i < N; i++)
            dist_s[i] = 1000000;
        dist_s[s] = 0;
        priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
        pq.push(make_pair(0,s));
        while (!pq.empty())
        {
            pair<int,int> front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist_s[u]) continue;
            for (int i = 0; i < link_s[u].size(); i++)
            {
                int v = link_s[u][i];
                if (dist_s[u] + cost_s[u][v] < dist_s[v]){
                    dist_s[v] = dist_s[u] + cost_s[u][v];
                    pq.push(make_pair(dist_s[v],v));
                }
            }
        }
        int dist_e[N];
        for (int i = 0; i < N; i++)
            dist_e[i] = 1000000;
        dist_e[t] = 0;
        pq.push(make_pair(0,t));
        while (!pq.empty())
        {
            pair<int,int> front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist_e[u]) continue;
            for (int i = 0; i < link_e[u].size(); i++)
            {
                int v = link_e[u][i];
                if (dist_e[u] + cost_e[u][v] < dist_e[v]){
                    dist_e[v] = dist_e[u] + cost_e[u][v];
                    pq.push(make_pair(dist_e[v],v));
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < link_s[i].size(); j++){
                int u = i, v = link_s[i][j];
                int w = cost_s[u][v];
                if (dist_s[u] + w + dist_e[v] <= p){
                    ans = max(ans,w);
                }
            }
        }
            
        if (dist_s[t] == 1000000) printf("-1\n");
        else printf("%d\n",ans);
    }
}


