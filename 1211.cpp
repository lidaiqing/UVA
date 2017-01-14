#include <bits/stdc++.h>

using namespace std;
#define MAX 105
int n;
int a[MAX];
double b,r,v,e,f;
double T[10005];
double dp[10005];
void input()
{
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> b >> r >> v >> e >> f;
}

void preprocess()
{
    T[0] = 0;
    for (int i = 0; i <= a[n]; i++)
    {
        if (i >= r) 
            T[i+1] = 1.0 / (v - e * (i - r)) + T[i];
        else
            T[i+1] = 1.0 / (v - f * (r - i)) + T[i];
       // cout << T[i] << endl;
    }
}

void solve()
{
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        double mi = 100000000;
        for (int j = 0; j < i; j++)
        {
            mi = min(mi, dp[j] + T[a[i]-a[j]]);
        }
        if (i != n) dp[i] = mi + b;
        else dp[i] = mi;
    }
    cout.setf(ios::fixed); 
    cout << setprecision(4) << dp[n] << endl;
}

int main()
{
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        input();
        preprocess();
        solve();
    }
}
