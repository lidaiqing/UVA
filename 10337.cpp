#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{

    int N;
    cin>>N;
    while(N--){
        
        int X;
        cin>>X;
        int num = X / 100;
        int w[10][num];
        for (int i = 9; i >= 0; i--){
            for (int j = 0; j < num; j++){
                cin>>w[i][j];
                w[i][j] = -w[i][j];
            }
        }
        
        int dp[10][num];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < num; j++)
                dp[i][j] = 0;
        dp[1][1] = 60 + w[0][0];
        for (int i = 2; i < num; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (dp[j-1][i-1] != 0){
                    if (dp[j][i] != 0)
                        dp[j][i] = min(dp[j][i], dp[j-1][i-1] + 60 + w[j-1][i-1]);
                    else dp[j][i] = dp[j-1][i-1] + 60 + w[j-1][i-1];
                }
                if (dp[j][i-1] != 0){
                    if (dp[j][i] != 0)
                        dp[j][i] = min(dp[j][i], dp[j][i-1] + 30 + w[j][i-1]);
                    else dp[j][i] = dp[j][i-1] + 30 + w[j][i-1];
                }
                if (j+1 <= 9 && dp[j+1][i-1] != 0){
                    if (dp[j][i] != 0)
                        dp[j][i] = min(dp[j][i], dp[j+1][i-1] + 20 + w[j+1][i-1]);
                    else dp[j][i] = dp[j+1][i-1] + 20 + w[j+1][i-1];
                }
            }
        }
       // cout<<dp[1][1]<<endl;
        int ans = dp[1][num-1] + 20 + w[1][num-1];
        cout<<ans<<endl;
        cout<<endl;
    }
}

