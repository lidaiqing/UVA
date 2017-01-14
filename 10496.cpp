#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n, m;
        cin>>n>>m;
        int st_x, st_y;
        cin>>st_x>>st_y;

        int b;
        cin>>b;
        int x[b+1], y[b+1];
        x[0] = st_x, y[0] = st_y;
        for(int i = 1; i <= b; i++)
            cin>>x[i]>>y[i];
        int dist[20][20];
        for(int i = 0; i <= b; i++)
            for(int j = 0; j <= b; j++)
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        int size = b+1;
        int dp[1<<size][size];
        
        for(int i = 0; i < (1<<size); i++)
            for(int j=0; j < size; j++)
                dp[i][j] = -1;
        dp[1][0] = 0;
        for(int i = 1; i < (1<<size); i++){
            for(int j =0; j < size; j++){
                
                if (dp[i][j] == -1) continue;
                for(int k = 1; k < size; k++)
                {
                    if(i & (1<<k)) continue;
                    int p = (i | (1<<k));
                    if (dp[p][k] == -1){
                        dp[p][k] = dp[i][j] + dist[j][k];
                    }
                    else{
                        if (dp[p][k] > dp[i][j] + dist[j][k])
                        {
                            dp[p][k] = dp[i][j] + dist[j][k];
                            
                        }
                    }
                }
            }
        }
        int ans = 10000000;
        for(int i = 1; i < size; i++)
        {
            if(dp[(1<<size)-1][i] != -1 && dp[(1<<size)-1][i] + dist[i][0] <ans)
                ans = dp[(1<<size)-1][i] + dist[i][0];
        }
        cout<<"The shortest path has length "<<ans<<endl;
    }
}


