#include <bits/stdc++.h>

using namespace std;
const int MAX = 15005;

int get_digits(long long n, int m)
{
    int digits = 0;
    int cnt = 1;
    int t = 1;
    while (cnt <= m)
    {
        int digit = n % 10;
        n /= 10;
        digits += digit * t;
        t *= 10;
        cnt++;
    }
    return digits;
}
int main()
{
    int T;
    cin>>T;
    int pisano[] = {0,60,300,1500,15000}, pow10[] = {1,10,100,1000,10000};
    while (T--)
    {
        int a,b,m;
        long long n;
        cin>>a>>b>>n>>m;
        int ans;
        n %= pisano[m];
        int fib[MAX];
        fib[0] = a % pow10[m];
        fib[1] = b % pow10[m];
        for (int i = 2; i < pisano[m] && i <= n; i++)
            fib[i] = (fib[i-1] + fib[i-2]) % pow10[m];
        cout<<fib[n]<<endl;

    }
}
