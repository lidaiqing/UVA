#include <bits/stdc++.h>

using namespace std;

#define MAX 5005
#define INF 100000000
bool visit[105][52][MAX];

int mx, mi;
int N, M;
int total;
int num[105];
void dfs(int idx, int l, int lsum)
{
    //cout << idx << " " << l << " " << lsum << endl;
    if (visit[idx][l][lsum+2500]) return;
    visit[idx][l][lsum+2500] = true;
    if (l == 0) {
        //lsum -= 2500;
        //cout << lsum << endl;
        mx = max(mx, lsum * (total - lsum));
        mi = min(mi, lsum * (total - lsum));
        return;
    }
    if (idx == N + M + 1) return;
    dfs(idx + 1, l - 1, lsum + num[idx]);
    dfs(idx + 1, l, lsum);
}

void solve()
{
    mx = -INF;
    mi = INF;
    memset(visit,false,sizeof(visit));
    dfs(1, N, 0);
    cout << mx << " " << mi << endl;
}

int main()
{
    while (cin >> N >> M)
    {
        total = 0;
        for (int i = 1; i <= N + M; i++)
        {
            cin >> num[i];
            total += num[i];
        }
        solve();
    }
}
        
