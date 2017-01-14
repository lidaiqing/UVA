#include <bits/stdc++.h>

using namespace std;
int main()
{
    int k, n;
    while (cin >> k) {
        cin >> n;
        double dp[n+1][k+1];
        for (int i = 0; i <= k; i++)
            dp[1][i] = 1.0 / (1 + k);
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = 0;
                for (int l = 0; l <= k; l++)
                {
                    if (abs(j-l) <= 1) {
                        dp[i][j] += (dp[i-1][l] / (1 + k));
                    }
                }
            }
        }
        cout.setf(ios::fixed);
        double sum = 0;
        for (int i = 0; i <= k; i++)
            sum += dp[n][i];
        sum *= 100;
        cout << setprecision(5) << sum << endl;
    }
}
        
