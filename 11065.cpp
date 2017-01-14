#include <bits/stdc++.h>

using namespace std;
#define MAX 70
long long adj[MAX];
int cnt_n, cnt_size;
int I, R;
void rec(int i, long long used, int d)
{
    if (used == (1LL << I) - 1) {
        cnt_n++;
        cnt_size = max(cnt_size, d);
        return;
    }
    for (int j = i; j < I; j++)
    {
        if (!(used & (1LL << j))) {
            rec(j + 1, (used | adj[j]), d + 1);
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cnt_n = 0;
        cnt_size = 0;
        cin >> I >> R;
        memset(adj,0,sizeof(adj));
        for (int i = 0; i < I; i++)
            adj[i] = (1LL << i);
        for (int i = 0; i < R; i++)
        {
            long long u, v;
            cin >> u >> v;
            adj[u] |= (1LL << v);
            adj[v] |= (1LL << u);
        }
        rec(0, 0, 0);
        cout << cnt_n << endl;
        cout << cnt_size << endl;
    }
}
        
