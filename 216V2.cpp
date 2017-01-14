#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <utility>

using namespace std;
pair<int, int>  parent[1<<10][25];
double dist[25][25];
int x[25], y[25];

void back_print(int xx, int yy)
{
    if (parent[xx][yy].first == -1 && parent[xx][yy].second == -1)  return;

    back_print(parent[xx][yy].first, parent[xx][yy].second);
    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2f feet.\n",x[parent[xx][yy].second],y[parent[xx][yy]. second],x[yy],y[yy],dist[yy][parent[xx][yy].second]);
}
int main()
{

    int cnt = 0;
    while(1)
    {

        int n;
        cin>>n;
        if(n == 0) break;
        cnt++;
        printf("**********************************************************\n");
        printf("Network #%d\n",cnt);
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j){
                    dist[i][j] = 16 + sqrt(abs((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
                }
            }
        }
        
        double dp[1<<n][n];
        for (int i = 0; i < (1<<n); i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = -1.0;
        dp[1][0] = 0;
        
        for(int i = 1; i < (1<<n); i++)
            parent[i][0] = make_pair(-1, -1);
        
        for(int i = 1; i < (1<<n); i++){
            for(int j = 0; j < n; j++){
                
                if (dp[i][j] == -1) continue;

                    for(int k = 1; k < n; k++)
                    {
                        if (i & (1<<k)) continue;
                        
                            int p = (i | (1<<k));
                            if (dp[p][k] == -1) {
                                dp[p][k] = dp[i][j] + dist[j][k];
                                parent[p][k] = make_pair(i, j);
                            }
                        
                            if (dp[p][k] > dp[i][j] + dist[j][k])
                            {
                                 dp[p][k] = dp[i][j] + dist[j][k];
                                 parent[p][k] = make_pair(i, j);
                             }
                            
                        
                    }
                }
            
        }
       // for(int i = 1; i < (1<<n); i++)
           // cout<<dp[i][5]<<" "<<i<<endl;
        double ans = 10000000, ind;
        for(int i = 1; i < n; i++)
        {
            if( dp[(1<<n)-1][i] != -1 && dp[(1<<n)-1][i] < ans)
               // cout<<dp[i][(1<<n)-1]<<endl;
            {
                ans = dp[(1<<n)-1][i];
                ind = i;
            }
        }
        //for(int i = 0; i < n; i++)
           // cout<<parent[i]<<endl;
        back_print((1<<n)-1, ind);
        printf("Number of feet of cable required is %0.2f.\n",ans);
    }
}
                        
