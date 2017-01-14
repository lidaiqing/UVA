#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    while (1)
    {
        int n,x;
        cin>>n>>x;
        if (n == 0 && x == 0) break;
        long long dp[n+1][150];
        memset(dp,0,sizeof(dp));
        dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j < 150; j++)
            {
                for (int k = 1; k <= 6; k++)
                {
                    if (j - k >= 1) 
                        dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        long long ans = 0;
        for (int i = x; i < 150; i++)
            ans += dp[n][i];
        long long all = pow(6,n);
        long long temp = gcd(ans,all);
        ans /= temp;
        all /= temp;
        if (ans == 0) cout<<"0"<<endl;
        else if (ans == all) cout<<"1"<<endl;
        else cout<<ans<<"/"<<all<<endl;
    }
}


