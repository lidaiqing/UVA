#include <bits/stdc++.h>

using namespace std;

char ori_graph[11][11];
char pro_graph[11][11];
string name;

bool input()
{
    cin >> name;
    if (name == "end") return false;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin >> ori_graph[i][j];
        }
    }
    return true;
}

void build(int r, int n)
{
    int dc[] = {-1,0,1};
    for (int i = 0; i < 10; i++)
    {
        if (n & (1 << i)) {
            for (int j = 0; j < 3; j++)
            {
                int cc = 10 - i + dc[j];
                if (cc > 0 && cc <= 10) {
                    pro_graph[r][cc] = (pro_graph[r][cc] == '#' ? 'O' : '#');
                }
            }
            if (r != 10) pro_graph[r+1][10-i] = (pro_graph[r+1][10-i] ==  '#' ? 'O' : '#');
            if (r != 1) pro_graph[r-1][10-i] = (pro_graph[r-1][10-i] == '#' ? 'O' : '#');
        }
    }
}

int process()
{
    int cnt = 0;
    for (int i = 2; i <= 10; i++)
    {
        int temp = 0;
        for (int j = 1; j <= 10; j++)
        {
            if (pro_graph[i-1][j] == 'O') {
                cnt++;
                temp |= (1 << (10 - j));
               // cout << j << endl;
            }
        }
        build(i,temp);
    }
   // cout << cnt << endl;
    return cnt;
}
bool check()
{
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (pro_graph[i][j] == 'O') return false;
    return true;
}
void solve()
{
    int ans = 100000000;
    for (int i = 0; i < (1 << 10); i++)
    {
        for (int j = 1; j <= 10; j++)
            for (int k = 1; k <= 10; k++)
                pro_graph[j][k] = ori_graph[j][k];
        build(1,i);
        
        int temp;
        temp = process();
        for (int j = 0; j < 10; j++)
            if (i & (1 << j))
                temp++;
        if (check()) {
            ans = min(ans, temp);
        }
    }
    cout << name << " " << ans << endl;
}

int main()
{
    while (1) {
    bool ok = input();
    if (!ok) return 0;
    solve();
    }
}

                



