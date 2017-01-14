#include <bits/stdc++.h>

using namespace std;

int mask;

void input()
{
    mask = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int ind = s.size() - i - 1;
        if (s[i] == 'o') mask |= (1 << ind);
    }
   // cout << mask << endl;
}

bool check(int n)
{
    for (int i = 0; i < 12; i++)
    {
        if (i - 1 >= 0 && i + 1 < 12) {
            if ( (n & (1 << i)) && (n & (1 << (i + 1))) && !(n & (1 << (i -1)))) return true;
        }
        if (i + 2 < 12) {
            if ( (n & (1 << i)) && (n & (1 << (i + 1))) && !(n & (1 << (i + 2)))) return true;
        }
    }
    return false;
}

int ans;

int count(int n)
{
    int cnt = 0;
    for (int i = 0; i < 12; i++)
        if (n & (1 << i)) cnt++;
    return cnt;
}

void dfs(int n)
{
    if (!check(n)) {
        ans = min(ans, count(n));
        return;
    }
    for (int i = 0; i < 12; i++)
    {
        if (i - 1 >= 0 && i + 1 < 12) {
            if ( (n & (1 << i)) && (n & (1 << (i + 1))) && !(n & (1 << (i -1)))) dfs((n | (1 << (i - 1))) ^ ((1 << (i + 1)) | (1 << i)));
        }
        if (i + 2 < 12) {
            if ( (n & (1 << i)) && (n & (1 << (i + 1))) && !(n & (1 << (i + 2)))) dfs((n | (1 << (i + 2))) ^ ((1 << (i + 1)) | (1 << i)));
        }
    }
}

void solve()
{
    ans = 100000000;
    dfs(mask);
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        input();
        solve();
    }
}

