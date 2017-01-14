#include <bits/stdc++.h>

using namespace std;
string number;
const int MAX = 205;
const long long LIMIT = 2147483648;

long long stringToint(string s)
{
    stringstream ss(s);
    long long ans;
    ss >> ans;
    return ans;
}
long long dp[MAX][MAX];
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        cin >> number;
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < number.size(); i++)
        {
            dp[i][i] = number[i] - '0';
        }
        for (int i = number.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < number.size(); j++)
            {
                if (j - i + 1 <= 13) {
                    long long tmp = stringToint(number.substr(i,j-i+1));
                    if (tmp < LIMIT) dp[i][j] = tmp;
                }
                long long mx = -1;
                for (int k = i; k < j; k++)
                {
                    //if (dp[i][k] < LIMIT && dp[k+1][j] < LIMIT)
                        mx = max(mx, dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] = max(dp[i][j], mx);
            }
        }
        cout<<dp[0][number.size()-1]<<endl;
    }
}
