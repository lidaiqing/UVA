#include <bits/stdc++.h>

using namespace std;
const int MAX = 15;
const int INF = 100000000;
const int MOD = 20437;
char mp[MAX][MAX];
int end_r, end_c;
int st_r, st_c;
pair<int,int> memo[MAX][MAX][28][105];
int cnt;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
int N;
bool visit[MAX][MAX];
int mi;
pair<int,int> go(int r,int c,int cur,int len)
{
   /* if (mp[r][c] >= 'A' && mp[r][c] <= 'Z')
        mp[r][c] = '.';*/
    if (r == end_r && c == end_c)
    {
        return make_pair(0,1);
    }
    if (memo[r][c][cur][len].first != -1) return memo[r][c][cur][len];
    //cout<<r<<" "<<c<<" "<<cur<<" "<<len<<endl;
    pair<int,int> ans;
    ans.first = INF;
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr >= 1 && rr <= N && cc >= 1 && cc <= N && mp[rr][cc] != '#' && !visit[rr][cc])
        {
            pair<int,int> next;
            next.first = INF;
            if (mp[rr][cc] == '.' || mp[rr][cc] - 'A' < cur) 
            {
                visit[rr][cc] = true;
                next = go(rr,cc,cur,len+1);
                visit[rr][cc] = false;
            }
            else if (mp[rr][cc] == 'A' + cur + 1)
            {
                visit[rr][cc] = true;
                next = go(rr,cc,cur+1,len+1);
                visit[rr][cc] = false;
            }
            
            if (next.first + 1 < ans.first)
            {
                ans.first = next.first + 1;
                ans.second = next.second;
            }
            else if (next.first + 1 == ans.first)
                ans.second += next.second;
        }
    }

    //cout<<r<<" "<<c<<" "<<cur<<" "<<ans<<endl;
    return memo[r][c][cur][len] = ans;
}

void cnt_path(int r,int c,int cur,int len)
{
    if (len > mi) return;
    if (r == end_r && c == end_c)
    {
        if (len == mi){
            cnt += 1;
            cnt %= MOD;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr >= 1 && rr <= N && cc >= 1 && cc <= N && mp[rr][cc] != '#' && !visit[rr][cc])
        {
            visit[rr][cc] = true;
            if (mp[rr][cc] == '.' && mp[rr][cc] - 'A' < cur)
                cnt_path(rr,cc,cur,len+1);
            else if (mp[rr][cc] == 'A' + cur + 1)
            {
                cnt_path(rr,cc,cur+1,len+1);
            }
            visit[rr][cc] = false;
        }
    }
}
int main()
{
    int ca = 0;
    while (1)
    {
        
        cin>>N;
        if (N == 0) break;
        ca++;
        char mx = 'A' - 1;
        vector<pair<char,pair<int,int> > >p;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin>>mp[i][j];
                if (mp[i][j] >= 'A' && mp[i][j] <= 'Z'){
                    p.push_back(make_pair(mp[i][j],make_pair(i,j)));
                }
            }
        }
        sort(p.begin(),p.end());
        cnt = 1;
        int ans = 0;
        for (int i = 0; i < p.size()-1; i++)
        {
            st_r = p[i].second.first, st_c = p[i].second.second;
            end_r = p[i+1].second.first, end_c = p[i+1].second.second;
            int cur = p[i].first - 'A';
            memset(memo,-1,sizeof(memo));
            memset(visit,false,sizeof(visit));
            pair<int,int> temp = go(st_r,st_c,cur,0);
            ans += temp.first;
            cnt *= temp.second;
            cnt %= MOD;
        }
        cout<<"Case "<<ca<<": ";
        if (cnt == 0) cout<<"Impossible"<<endl;
        else cout<<ans<<" "<<cnt<<endl;
    }
}
        
        




