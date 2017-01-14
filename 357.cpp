#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{

    int n;
    int coins[6] = {0, 1, 5, 10, 25, 50};
    
    
        
        long long dp[6][30001];
        memset(dp, 0, sizeof(dp));

        for(int i=0;i<=5;i++)
            dp[i][0] = 1;

        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=30000;j++)
            {
                dp[i][j] = dp[i-1][j];
                if( j - coins[i] >= 0 ) 
                    dp[i][j] += dp[i][j-coins[i]];
            }
        }
        while(cin>>n){
        long long ans = dp[5][n];
        if(ans == 1) printf("There is only 1 way to produce %d cents change.\n",n);
        else cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change."<<endl;
    }
}

        
        
