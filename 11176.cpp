#include <bits/stdc++.h>

using namespace std;

int n;
double p;
double memo[505][505];
double go(int n_left,int streak)
{
    if (n_left == 0 && streak == 1) return p;
    if (n_left == 0 && streak == 0) return (1.0 - p);
    if (n_left == 0) return 1.0;
    if (memo[n_left][streak] != -1) return memo[n_left][streak];
    double ans = 0;
    ans += go(n_left-1,streak) * (1.0 - p);
    //cout<<ans<<endl;
    for (int i = 1; i < n_left; i++)
    {
        if (i <= streak) ans += go(n_left-i-1,streak) * pow(p,i) * (1.0 - p);
        else ans += go(n_left-i-1,i) * pow(p,i) * (1.0 - p);
    }
    if (n_left > streak) ans += go(0,n_left) * pow(p,n_left);
    else ans += go(0,streak) * pow(p,n_left);
    cout<<n_left<<" "<<streak<<" "<<ans<<endl;
    return memo[n_left][streak] = ans;
}
int main()
{
    while (1)
    {
        cin >> n >> p;
        if (n == 0) break;
        for (int i = 0; i < 505; i++)
            for (int j = 0; j < 505; j++)
                memo[i][j] = -1;
        go(n,0);
        double ans = 0;
        for (int i = 0; i <= n; i++)
            cout<<memo[n][i]<<endl;;
        cout<<ans<<endl;
    }
}

    
