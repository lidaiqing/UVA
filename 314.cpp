#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
struct node{
    int r,c;
    int dic;
    int sec_cnt;
};
int main()
{
    while (1)
    {
        int M,N;
        cin>>M>>N;
        if (M == 0 && N == 0) break;
        int block[M][N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin>>block[i][j];
        int mp[M+1][N+1];
        memset(mp,-1,sizeof(mp));
        node st,end;
        cin>>st.r>>st.c>>end.r>>end.c;
        st.sec_cnt = 0;
        string dic;
        cin>>dic;
        if (dic == "south") st.dic = 1;
        else if (dic == "north") st.dic = 3;
        else if (dic == "west") st.dic = 2;
        else st.dic = 0;
        int dr[] = {0,0,1,1};
        int dc[] = {0,1,1,0};
        for (int i = 0; i < M+1; i++){
            for (int j = 0; j < N+1; j++){
                if (i == 0 || j == 0 || i == M || j == N)
                    mp[i][j] = 1;
                if (block[i][j]){
                    for (int k = 0; k < 4; k++){
                        int rr = i + dr[k];
                        int cc = j + dc[k];
                        if (rr >= 0 && rr < M+1 && cc >= 0 && cc < N+1)
                            mp[rr][cc] = 1;
                    }
                }
            }
        }
       /* for (int i = 0; i < M+1; i++){
            for (int j = 0; j < N+1; j++){
                cout<<mp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        mp[st.r][st.c] = 0;
        queue <node> q;
        q.push(st);
        int ans = -1;
        int visit[M+1][N+1][4];
        memset(visit,0,sizeof(visit));
        visit[st.r][st.c][st.dic] = 1;
        while (!q.empty())
        {
            node u = q.front();//cout<<u.r<<" "<<u.c<<" "<<u.dic<<" "<<u.sec_cnt<<endl;
            q.pop();
            if (u.r == end.r && u.c == end.c){
                ans = u.sec_cnt;
                break;
            }
            int dic = (u.dic + 1) % 4;
                if (!visit[u.r][u.c][dic]){
                    node temp = u;
                    temp.dic = dic;
                    temp.sec_cnt = u.sec_cnt + 1;
                    q.push(temp);
                    visit[u.r][u.c][dic] = 1;
                }
            dic = ((u.dic - 1) + 4) % 4;
                if (!visit[u.r][u.c][dic]){
                    node temp = u;
                    temp.dic = dic;
                    temp.sec_cnt = u.sec_cnt + 1;
                    q.push(temp);
                    visit[u.r][u.c][dic] = 1;
                }

            if (u.dic == 0){
                for (int i = 1; i <= 3; i++){
                    int cc = u.c + i;
                    int rr = u.r;
                    bool flag = true;
                    for (int j = u.c; j <= cc; j++){
                        if (j >= N+1 || mp[rr][j] == 1)
                            flag = false;
                    }
                    if (flag && mp[rr][cc] == -1){
                        mp[rr][cc] = 0;
                        node temp = u;
                        temp.c = cc;
                        temp.sec_cnt++;
                        q.push(temp);
                    }
                }
            }
            else if (u.dic == 1){
                 for (int i = 1; i <= 3; i++){
                    int cc = u.c;
                    int rr = u.r + i;
                    bool flag = true;
                    for (int j = u.r; j <= rr; j++){
                        if (j >= M+1 || mp[j][cc] == 1)
                            flag = false;
                    }

                    if (flag && mp[rr][cc] == -1){
                        mp[rr][cc] = 0;
                        node temp = u;
                        temp.r = rr;
                        temp.sec_cnt++;
                        q.push(temp);
                    }
                }
            }
            else if (u.dic == 2){
                 for (int i = 1; i <= 3; i++){
                    int cc = u.c - i;
                    int rr = u.r;
                    bool flag = true;
                    for (int j = u.c; j >= cc; j--){
                        if (j < 0 || mp[rr][j] == 1)
                            flag = false;
                    }

                    if (flag && mp[rr][cc] == -1){
                        mp[rr][cc] = 0;
                        node temp = u;
                        temp.c = cc;
                        temp.sec_cnt++;
                        q.push(temp);
                    }
                }
            }
            else {
                for (int i = 1; i <= 3; i++){
                    int cc = u.c;
                    int rr = u.r - i;
                    bool flag = true;
                    for (int j = u.r; j >= rr; j--){
                        if (j < 0 || mp[j][cc] == 1)
                            flag = false;
                    }

                    if (flag && mp[rr][cc] == -1){
                        mp[rr][cc] = 0;
                        node temp = u;
                        temp.r = rr;
                        temp.sec_cnt++;
                        q.push(temp);
                    }
                }
            }
        }
        
        cout<<ans<<endl;
    }
}



                    


                            
