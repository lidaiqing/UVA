#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
double eps = 0.000000001;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,M;
        cin>>N>>M;
        double dist[N+1][N+1];
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                if (i != j) dist[i][j] = 10000000;
                else dist[i][j] = 0;
            }
        }
        for(int i = 1; i <= M; i++)
        {
            int a, b;
            cin>>a>>b;
            double c;
            cin>>c;
            dist[a][b] = min(dist[a][b],c);
            dist[b][a] = dist[a][b];
        }
        int P;
        cin>>P;
        double price[N+1];
        int list[P+1];
        list[0] = 0;
        for(int i = 0; i <= N; i++)
            price[i] = 0;
        for(int i = 1; i <= P; i++)
        {
            int a;
            double b;
            cin>>a>>b;
            price[i] = b;
            list[i] = a;
        }
        for(int k = 0; k <= N; k++){
            for(int i = 0; i <= N; i++){
                for(int j = 0; j <=N; j++){
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        int size = P+1;
        double dp[1<<size][size];
        double ddist[size][size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                ddist[i][j] = dist[list[i]][list[j]];
        for (int i = 0; i < (1<<size); i++)
            for (int j = 0; j < size; j++)
                dp[i][j] = -1;
        dp[1][0] = 0;
        
        for (int i = 1; i < (1<<size); i++){
            for (int j = 0; j < size; j++){
                if (dp[i][j] == -1) continue;

                for (int k = 1; k < size; k++)
                {
                    if (i & (1<<k)) continue;
                    
                    int p = (i | (1<<k));
                    if (dp[p][k] == -1){
                        dp[p][k] = dp[i][j] + price[k] - ddist[j][k];
                    }
                    else{
                        dp[p][k] = max(dp[p][k], dp[i][j] + price[k] - ddist[j][k]);
                    }
                }
            }
        }
        double ans = -1;
        for (int i = 1; i < (1<<size); i++){
            for(int j = 0; j < size; j++){
                double save = 0;
                for(int k = 0; k < size; k++){
                    if (!(i & (1<<k)))
                        save += price[k];
                double temp = dp[i][j] - save - ddist[j][0];
                ans = max(ans, temp);
                }
            }
        }
        if (ans <= 0 + eps) printf("Don't leave the house\n");
        else printf("Daniel can save $%.2f\n",ans);
    }
}
                        
                        


        
        
