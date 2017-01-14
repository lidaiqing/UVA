#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while (cin>>s)
    {
        int n = s.size();
        long long dp[n][n];
        memset(dp,0,sizeof(dp));
        if (s[0] == '?')
        {
            for (int i = 0; i < n; i++)
                dp[0][i] = 1;
        }
        else {
            int ind;
            if (s[0] >= '1' && s[0] <= '9')
                ind = s[0] - '0' - 1;
            else
                ind = s[0] - 'A' + 9;
            dp[0][ind] = 1;
        }
       // cout<<"asd"<<endl;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '?')
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < j - 1; k++)
                        dp[i][j] += dp[i-1][k];
                    for (int k = j + 2; k < n; k++)
                        dp[i][j] += dp[i-1][k];
                }
            }
            else
            {
                int ind;
                if (s[i] >= '1' && s[i] <= '9')
                    ind = s[i] - '0' - 1;
                else
                    ind = s[i] - 'A' + 9;
                for (int k = 0; k < ind - 1; k++)
                    dp[i][ind] += dp[i-1][k];
                for (int k = ind + 2; k < n; k++)
                    dp[i][ind] += dp[i-1][k];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += dp[n-1][i];
        cout<<ans<<endl;
    }
}
