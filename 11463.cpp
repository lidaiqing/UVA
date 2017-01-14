#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int cnt = 0;
    while (T--)
    {
        cnt++;
        int N,R;
        cin>>N>>R;
        int dist[N][N];
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = 1000000;
            }
        }
        for (int i = 0; i < R; i++){
            int u,v;
            cin>>u>>v;
            dist[u][v] = 1;
            dist[v][u] = 1;
        }
        int s,d;
        cin>>s>>d;

        for (int k = 0; k < N; k++){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < N; i++)
        {
            ans = max(ans,dist[s][i]+dist[i][d]);
        }
        cout<<"Case "<<cnt<<": "<<ans<<endl;
    }
}
