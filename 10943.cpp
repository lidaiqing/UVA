#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{

    int N, K;
    while(1)
    {
        cin>>N>>K;
        if (N == 0 && K == 0) break;

        long long dp[N+1][K+1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= N; i++)
            dp[i][1] = 1;
        for (int i = 0; i <= N; i++){
            for (int j = 2; j <= K; j++){
                for(int k = 0; k <= i; k++){
                    dp[i][j] += dp[i-k][j-1]%1000000;
                    dp[i][j] %= 1000000;
                }
            }
        }
    
        cout<<dp[N][K]<<endl;
    }
}
