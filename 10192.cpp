#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
const int INF = 100000000;
int dp[MAX][MAX];
int main()
{
    int cnt = 0;
    while (1)
    {
        cnt++;
        string a, b;
        getline(cin,a);
        if (a == "#") break;
        getline(cin,b);
        dp[0][0] = 0;
        for (int i = 1; i < MAX; i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= b.size(); j++)
            {
                if (a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else {
                    //if (dp[i-1][j-1] >= dp[i-1][j] && dp[i-1][j-1] >= dp[i][j-1])
                        //dp[i][j] = dp[i-1][j-1] - INF;
                    if (dp[i-1][j] >= dp[i-1][j-1] && dp[i-1][j] >= dp[i][j-1])
                        dp[i][j] = dp[i-1][j];
                    else if (dp[i][j-1] >= dp[i-1][j-1] && dp[i][j-1] >= dp[i-1][j])
                        dp[i][j] = dp[i][j-1];
                }
            }
        }
        cout<<"Case #"<<cnt<<": you can visit at most "<<dp[a.size()][b.size()]<<" cities."<<endl;
    }
}

        
