#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>

using namespace std;
struct node{
    int r,c;
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
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N,M;
        scanf("%d %d",&N,&M);
        int cost[N][M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d",&cost[i][j]);
        int dist[N][M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                dist[i][j] = 10000000;
        dist[0][0] = cost[0][0];
        priority_queue < pair<int,node>, vector<pair<int,node> >, comp > pq;
        node st;
        st.r = 0,st.c = 0;
        pq.push(make_pair(cost[0][0],st));
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        bool visit[N][M];
        memset(visit,false,sizeof(visit));
        while (!pq.empty())
        {
            pair<int,node> front = pq.top();
            pq.pop();
            int d = front.first, r = front.second.r, c = front.second.c;
            //if (visit[r][c]) continue;
           // visit[r][c] = true;
            if (d > dist[r][c]) continue;
            for (int i = 0; i < 4; i++)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (rr >= 0 && rr < N && cc >= 0 && cc < M){
                if (dist[r][c] + cost[rr][cc] < dist[rr][cc]){
                    dist[rr][cc] = dist[r][c] + cost[rr][cc];
                    node temp;
                    temp.r = rr, temp.c = cc;
                    pq.push(make_pair(dist[rr][cc],temp));
                }
                }
            }
        }
        printf("%d\n",dist[N-1][M-1]);
    }
}
                    
            
