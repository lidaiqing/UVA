#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

pair<long long, int> dp[MAX][MAX];
int N, M;
string north_type[MAX];
string south_type[MAX];
int north_val[MAX];
int south_val[MAX];
void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string name, type;
        int val;
        cin >> name >> type >> val;
        north_type[i] = type;
        north_val[i] = val;
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        string name, type;
        int val;
        cin >> name >> type >> val;
        south_type[i] = type;
        south_val[i] = val;
    }
}

void solve()
{
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
        {
            dp[i][j].first = 0;
            dp[i][j].second = 0;
        }
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (north_type[i] == south_type[j]) {
                if (dp[i][j].first < dp[i-1][j-1].first + north_val[i] + south_val[j]) {
                    dp[i][j].first = dp[i-1][j-1].first + north_val[i] + south_val[j];
                    dp[i][j].second = dp[i-1][j-1].second + 1;
                }
            }
            if (dp[i][j].first < dp[i-1][j].first) {
                dp[i][j].first = dp[i-1][j].first;
                dp[i][j].second = dp[i-1][j].second;
            }
            if (dp[i][j].first < dp[i][j-1].first) {
                dp[i][j].first = dp[i][j-1].first;
                dp[i][j].second = dp[i][j-1].second;
            }
        }
    }
    long long mx_val = 0, mi_num;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (dp[i][j].first > mx_val) {
                mx_val = dp[i][j].first;
                mi_num = dp[i][j].second;
            }
            else if (dp[i][j].first == mx_val) {
                if (dp[i][j].second < mi_num)
                    mi_num = dp[i][j].second;
            }
        }
    }
    cout << mx_val << " " << mi_num << endl;
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
        


