#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;
const int INF = 10000000;

int mp[MAX][MAX];
int N,k;
int memo[MAX][MAX][10][3];
int go(int r,int c,int neg_left,int stat)
{
    if (neg_left < 0) return -INF;
    if (r == N && c == N) return mp[N][N];
    if (memo[r][c][neg_left][stat] != -1) return memo[r][c][neg_left][stat];
    int ans = -INF;
   // cout<<r<<"sb "<<c<<" "<<stat<<endl;
    int down,left,right;
    if (r + 1 <= N) {
        if (mp[r+1][c] < 0) down = go(r+1,c,neg_left-1,0);
        else down = go(r+1,c,neg_left,0);
    }
    else down = -INF;
    if (c - 1 >= 1 && stat != 1) {
        if (mp[r][c-1] < 0) left = go(r,c-1,neg_left-1,2);
        else left = go(r,c-1,neg_left,2);
    }
    else left = -INF;
    if (c + 1 <= N && stat != 2) {
        if (mp[r][c+1] < 0) right = go(r,c+1,neg_left-1,1);
        else right = go(r,c+1,neg_left,1);
    }
    else right = -INF;
   if (down != -INF) ans = max(ans, mp[r][c] + down);
   if (left != -INF) ans = max(ans, mp[r][c] + left);
   if (right != -INF) ans = max(ans, mp[r][c] + right);
    //cout<<r<<"sb "<<c<<" "<<ans<<endl;
    return memo[r][c][neg_left][stat] = ans;
}
    
int main()
{
    int cnt = 0;
    while (1)
    {
        
        cin>>N>>k;
        if (N == 0 && k == 0) break;
        cnt++;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin>>mp[i][j];
        int ans;
        memset(memo,-1,sizeof(memo));
        if (mp[1][1] < 0)
            ans = go(1,1,k-1,0);
        else
            ans = go(1,1,k,0);
        cout<<"Case "<<cnt<<": ";
        if (ans == -INF) cout<<"impossible"<<endl;
        else cout<<ans<<endl;
    }
}

