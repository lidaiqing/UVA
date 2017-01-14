#include <bits/stdc++.h>

using namespace std;
const int MAX = 605;
const int INF = 100000000;
int dist[MAX][MAX];
int memo[MAX][MAX];
int N,K;
int go(int cur, int night_left)
{
    if (night_left < 0) return INF;
    if (cur == N + 1) return 0;
    if (memo[cur][night_left] != -1) return memo[cur][night_left];
    int ans = INF;
    for (int i = cur + 1; i <= N + 1; i++)
    {
        int temp = -1;
        if (i != cur)
        {
            int next = go(i,night_left - 1);
            temp = max(dist[cur][i], next);
        }
        ans = min(ans,temp);
    }
    return memo[cur][night_left] = ans;
}

int main()
{
    while (cin>>N){
    cin>>K;
    int sum[N+2];
    sum[0] = 0;
    for (int i = 1; i <= N+1; i++)
    {
        int temp;
        cin>>temp;
        sum[i] = temp + sum[i-1];
    }
    for (int i = 0; i <= N+1; i++)
    {
        for (int j = i+1; j <= N+1; j++)
        {
            dist[i][j] = sum[j] - sum[i];
            //cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
        }
    }
    memset(memo,-1,sizeof(memo));
    int ans = go(0,K+1);
    cout<<ans<<endl;
    }
}

    

