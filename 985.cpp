#include <bits/stdc++.h>

using namespace std;

struct state {
    int dir;
    int rotate;
    int r, c;
    int dist;
};

#define MAX 505
#define INF 1000000
int R, C;
state graph[MAX][MAX];
void input()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == R-1 && j == C-1) break;
            state temp;
            string s;
            cin >> s;
            temp.rotate = 0;
            temp.r = i;
            temp.c = j;
            temp.dir = 0;
            for (int k = 0; k < s.size(); k++)
            {
                if (s[k] == 'W') temp.dir |= (1 << 3);
                if (s[k] == 'N') temp.dir |= (1 << 2);
                if (s[k] == 'E') temp.dir |= (1 << 1);
                if (s[k] == 'S') temp.dir |= 1;
            }
            graph[i][j] = temp;
        }
    }
    state temp;
    temp.dir = 0;
    temp.rotate = 0;
    temp.r = R-1, temp.c = C-1;
    graph[R-1][C-1] = temp;
}
int rotate(int dir)
{
    int bit = (dir & 1);
    bit = (bit << 3);
    int ddir = (dir >> 1);
    ddir |= bit;
    return ddir;
}
int get_dir(state s, int r)
{
   if (r == 0) return s.dir;
   if (r == 1) {
      int dir = rotate(s.dir);
      return dir;
   }
   if (r == 2) {
       int dir = rotate(s.dir);
       dir = rotate(dir);
       return dir;
   }
   if (r == 3) {
       int dir = rotate(s.dir);
       dir = rotate(dir);
       dir = rotate(dir);
       return dir;
   }
}
bool visit[MAX][MAX][4];
void solve() {
    int ans = INF;
    queue <state> q;
    state st = graph[0][0];
    st.dist = 0;
    q.push(st);
    memset(visit,false,sizeof(visit));
    int dr[] = {0,-1,0,1};
    int dc[] = {-1,0,1,0};
    while (!q.empty())
    {
        state u = q.front();
        //cout << u.r << " " << u.c << " " << u.dir << " " << u.rotate << endl;
        q.pop();
        if (visit[u.r][u.c][u.rotate]) continue;
        visit[u.r][u.c][u.rotate] = true;
        if (u.r == R-1 && u.c == C-1) {
            ans = min(ans, u.dist);
        }
        for (int i = 0; i < 4; i++)
        {
            int rr = u.r + dr[i];
            int cc = u.c + dc[i];
            if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
                //cout << rr << " " << cc << endl;
                if (u.dir & (1 << (3 - i))) {
                    state temp = graph[rr][cc];
                    temp.dist = u.dist + 1;
                    temp.rotate = (u.rotate + 1) % 4;
                    temp.dir = get_dir(temp, temp.rotate);
                    q.push(temp);
                }
            }
        }
    }
    if (ans == INF) cout << "no path to exit" << endl;
    else cout << ans << endl;
}

int main()
{
    while (cin >> R >> C) {
        input();
        solve();
    }
}


    

