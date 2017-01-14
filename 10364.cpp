#include <bits/stdc++.h>

using namespace std;

#define MAX (1 << 22)

int dp[5][MAX];
int M;
int length[25];
int countbit(int n)
{
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        if (n & (1 << i))
            cnt++;
    }
    return cnt;
}
int get_sum(int n)
{
    int sum = 0;
    for (int i = 0; i < M; i++)
    {
        if (n & (1 << i)) sum += length[i];
    }
    return sum;
}
int target;
int can(int n, int s)
{
   // cout << n << " " << s << endl;
    if (dp[n][s] != -1) return dp[n][s];
    if (n == 1 && get_sum(s) == target) return dp[n][s] = 1;
    if (n == 1 && get_sum(s) != target) return dp[n][s] = 0;
    if (n == 0) return dp[n][s] = 1;
    
    if (get_sum(s) != target * n) return dp[n][s] = 0;
    //cout << "asds" << endl;
    for (int s1 = (s & (s-1)); s1 > 0; s1 = (s1-1) & s)
    {
        int s2 = s1 ^ s;
        if (n >= 1 && can(1,s1) && can(n-1,s2))
            return dp[n][s] = 1;
        if (n >= 1 && can(1,s2) && can(n-1,s1))
            return dp[n][s] = 1;
    }
    return dp[n][s] = 0;
}


int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        cin >> M;
        int sum = 0;
        for (int i = 0; i < M; i++)
        {
            cin >> length[i];
            sum += length[i];
        }
        if (sum % 4) {
            cout << "no" << endl;
            continue;
        }
        target = sum / 4;
        memset(dp,-1,sizeof(dp));
        //cout << "asd" << endl;
        if (can(4,(1<<M)-1)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}

