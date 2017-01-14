#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

struct node{
    int r,c;
};
int main()
{
    int T;
    cin>>T;
    int ca = 0;
    while(T--)
    {
        ca++;
        int R, C, M, N;
        cin>>R>>C>>M>>N;
        int W;
        cin>>W;
        bool visit[R][C];
        bool water[R][C];
        int cnt[R][C];
        memset(water, false, sizeof(water));
        memset(visit, false, sizeof(visit));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < W; i++)
        {
            int r, c;
            cin>>r>>c;
            water[r][c] = true;
        }
        int dr[] = {-M, -M, M, M, -N, -N, N, N};
        int dc[] = {N, -N, N, -N, M, -M, M, -M};
        node st;
        st.r = 0;
        st.c = 0;
        queue <node> q;
        q.push(st);
        while(!q.empty()){
            node top = q.front();
            q.pop();
            if (visit[top.r][top.c]) continue;
            visit[top.r][top.c] = true;
            bool vvisit[R][C];
            memset(vvisit,false, sizeof(vvisit));
            for (int i = 0; i < 8; i++)
            {
                int rr = top.r + dr[i];
                int cc = top.c + dc[i];
                if (rr >= 0 && rr < R && cc >= 0 && cc < C && !water[rr][cc])
                {
                    if (!vvisit[rr][cc]) {
                       cnt[top.r][top.c]++;
                       vvisit[rr][cc] = true;
                   }
                }
            }
            for (int i = 0; i < 8; i++)
            {
                int rr = top.r + dr[i];
                int cc = top.c + dc[i];
                node temp;
                temp.r = rr;
                temp.c = cc;
                if (rr >= 0 && rr < R && cc >= 0 && cc < C && !water[rr][cc])
                    q.push(temp);
            }
        }
        int even = 0, odd = 0;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (cnt[i][j] != 0 && cnt[i][j] % 2 == 0)
                    even++;
                else if (cnt[i][j] != 0 && cnt[i][j] % 2 != 0)
                    odd++;
            }
        }
        if (even == 0 && odd == 0)
            cout<<"Case "<<ca<<": "<<"1 0"<<endl;
        else
            cout<<"Case "<<ca<<": "<<even<<" "<<odd<<endl;
    }
}
            


            
