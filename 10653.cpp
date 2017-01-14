#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
#include <sstream>
using namespace std;
struct node{
    int r,c;
};
int main()
{
    while (1)
    {
        int R,C;
        cin>>R>>C;
        if (R == 0 && C == 0) break;
        int mp[R][C];
        memset(mp,-1,sizeof(mp));
        int rows;
        cin>>rows;
        for (int i = 0; i < rows; i++)
        {
            int r,n,c;
            cin>>r>>n;
            while (n--)
            {
                //cout<<c<<endl;
                cin>>c;
                mp[r][c] = 0;
            }
        }
        node st,end;
        cin>>st.r>>st.c;
        cin>>end.r>>end.c;

        queue <node> q;
        q.push(st);
        int dist[R][C];
        memset(dist,-1,sizeof(dist));
        dist[st.r][st.c] = 0;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int ans;
        while (!q.empty())
        {
            node u = q.front();
            q.pop();
            bool flag = false;
            for (int i = 0; i < 4; i++)
            {
                int rr,cc;
                rr = u.r + dr[i];
                cc = u.c + dc[i];
                if (rr >= 0 && rr < R && cc >= 0 && cc < C && mp[rr][cc] == -1){
                    mp[rr][cc] = 1;
                    dist[rr][cc] = dist[u.r][u.c] + 1;//cout<<rr<<" "<<cc<<endl;
                    if (rr == end.r && cc == end.c){
                        ans = dist[rr][cc];//cout<<"asd"<<endl;
                        flag = true;
                        break;
                    }
                    else {
                        node temp;
                        temp.r = rr;
                        temp.c = cc;
                        q.push(temp);
                    }
                }
            }
            if (flag) break;
        }
        cout<<ans<<endl;
    }
}

        
