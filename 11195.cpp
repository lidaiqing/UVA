#include <bits/stdc++.h>

using namespace std;
#define MAX 16
int n;
int block[MAX];
int cnt;
void dfs(int cur, int l, int r, int row)
{
    if (cur == n) {
        cnt++;
        return;
    }
    int ok = (1 << n) - 1;
    int can = (~(l | r | row | block[cur])) & ok;
    while (can) {
        int p = can & -can;
        dfs(cur+1, (l | p) >> 1, (r | p) << 1, row | p);
        can -= p;
    }
}
int main()
{
    int case_num = 0;
    while (1)
    {
        case_num++;
        cin >> n;
        if (n == 0) break;
        cnt = 0;
        memset(block,0,sizeof(block));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char temp;
                cin >> temp;
                if (temp == '*') {
                    block[i] |= (1 << (n - j - 1));
                }
            }
        }
        dfs(0,0,0,0);
        cout << "Case " << case_num << ": " << cnt << endl;
    }
}
