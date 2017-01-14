#include <bits/stdc++.h>

using namespace std;

int I, C;

int combo[10][10];
int price[10];
int combo_val[10];
int order[10];
void input()
{
    //cin >> I;
    for (int i = 0; i < I; i++)
        cin >> price[i];
    cin >> C;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < I; j++) {
            cin >> combo[i][j];
        }
        cin >> combo_val[i];
    }
}
bool check(int _order[])
{
    
    for (int i = 0; i < C; i++)
    {
        bool ok = true;
        for (int j = 0; j < I; j++)
            if (_order[j] < combo[i][j]) ok = false;
        if (ok) return true;
    }
    return false;
}
int mi;
void dfs(int _order[], int val)
{
    if (!check(_order)) {
        int temp = val;
        for (int i = 0; i < I; i++)
            if (_order[i] > 0) temp += price[i] * _order[i];
        mi = min(temp, mi);
        return;
    }
    for (int i = 0; i < C; i++)
    {
        bool ok = true;
        for (int j = 0; j < I; j++)
            if (_order[j] < combo[i][j]) ok = false;
        if (ok) {
            for (int j = 0; j < I; j++)
                _order[j] -= combo[i][j];
            dfs(_order, val + combo_val[i]);
            for (int j = 0; j < I; j++)
                _order[j] += combo[i][j];
        }
    }
}

void solve()
{
    mi = 1000000000;
    dfs(order, 0);
    cout << mi << endl;
}

int main()
{
    while (cin >> I) {
    input();
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < I; i++)
            cin >> order[i];
        solve();
    }
    }
}


    
