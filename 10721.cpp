#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{

    int n, k, m;
   while( cin>>n>>k>>m){

    long long dp[55][55];
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n && i <= m; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= k; i++){
        for (int j = i; j <= n; j++){
            for(int l = 1; l <= m && l < j; l++){

                dp[i][j] += dp[i-1][j-l];
            }
        }
    }
    cout<<dp[k][n]<<endl;
   }
}
