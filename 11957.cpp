#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e6 + 7;
int main()
{
    int T;
    cin>>T;
    int cnt = 0;
    while (T--)
    {
        cnt++;
        int N;
        cin>>N;
        char mp[N+1][N+1];
        long long dp[N+1][N+1];
        memset(dp,0,sizeof(dp));
        int st = 1;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin>>mp[i][j];
                if (mp[i][j] == 'W' && i != 1)
                {
                    dp[i][j] = 1;
                    st = i;
                }
            }
        }
        for (int i = st-1; i >= 1; i--)
        {
            for (int j = 1; j <= N; j++)
            {
                if (mp[i][j] == '.')
                {
                    for (int k = 1; k <= 2; k++)
                    {
                        int r = i + k;
                        int c = j - k;
                        if (r <= N && c >= 1 && mp[r][c] != 'B')
                        {
                            dp[i][j] = (dp[i][j] + dp[r][c]) % MOD;
                            break;
                        }
                    }
                    for (int k = 1; k <= 2; k++)
                    {
                        int r = i + k;
                        int c = j + k;
                        if (r <= N && c <= N && mp[r][c] != 'B')
                        {
                            dp[i][j] = (dp[i][j] + dp[r][c]) % MOD;
                            break;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= N; i++)
        {
            if (mp[1][i] != 'B')
                ans = (ans + dp[1][i]) % MOD;
        }
        
        cout<<"Case "<<cnt<<": "<<ans<<endl;
    }
}

