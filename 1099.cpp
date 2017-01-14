#include <bits/stdc++.h>

using namespace std;

#define MAX 17

int N;
int num[MAX];
int X, Y;
int sum[(1<<MAX)];
int countbit(int n)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (n & (1 << i))
            cnt++;
    return cnt;
}
int dp[(1<<MAX)][105];
bool dfs(int s, int x)
{
    if (dp[s][x] != -1) return dp[s][x];
    if (countbit(s) == 1) return dp[s][x] = 1;
    if (sum[s] % x) return dp[s][x] = 0;
    int y = sum[s] / x;
    for (int s0 = (s-1) & s; s0 > 0; s0 = (s0-1) & s)
    {
        int s1 = s0 ^ s;
        if (sum[s0] % x == 0 && sum[s1] % x == 0 && dfs(s0,min(x,sum[s0]/x)) && dfs(s1,min(x,sum[s1]/x)))
            return dp[s][x] = 1;
        if (sum[s0] % y == 0 && sum[s1] % y == 0 && dfs(s0,min(y,sum[s0]/y)) && dfs(s1,min(y,sum[s1]/y)))
            return dp[s][x] = 1;
    }
    return dp[s][x] = false;
}

int main()
{
    int case_num = 0;
    while (1)
    {
        cin >> N;
        if (N == 0) break;
        case_num++;
        cin >> X >> Y;
        for (int i = 0; i < N; i++)
            cin >> num[i];
        memset(sum,0,sizeof(sum));
        for (int i = 0; i < (1 << N); i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i & (1 << j))
                    sum[i] += num[j];
            }
        }
        if (sum[(1 << N)-1] != X * Y) {
            cout << "Case " << case_num << ": No" << endl;
        }
        else {
            memset(dp,-1,sizeof(dp));
            cout << "Case " << case_num << ": ";
            cout << (dfs((1<<N)-1,min(X,Y)) ? "Yes" : "No") << endl;
        }
    }
}
            

        

