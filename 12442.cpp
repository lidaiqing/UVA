#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    int ca = 0;
    while(t--)
    {
        int N;
        cin>>N;
        ca++;
        vector <int> v[N+1];
       // int color[N+1];
        bool visit[N+1];
        //int num[N+1];
        //int parent[N+1];
        memset(visit,false,sizeof(visit));
       // memset(color,-1, sizeof(color));
        //memset(num, 0, sizeof(num));
        //memset(parent, -1, sizeof(parent));
       // cout<<num[1]<<endl;
        for (int i = 1; i <= N; i++)
        {
            int u ,vv;
            cin>>u>>vv;
            v[u].push_back(vv);
        }
        int max_cnt = 0, ans, now_color = 1;
        for (int i = 1; i <= N; i++)
        {
            //now_color = i;
            bool temp_visit[N+1];
            memset(temp_visit,false,sizeof(temp_visit));
            if (!visit[i]){
                //parent[i] = i;
            stack <int> q;
            q.push(i);
            int cnt = 0;
            while(!q.empty())
            {
                int top = q.top();
                q.pop();
                if (temp_visit[top]) {
                    //if (color[top] != now_color && !temp_visit[color[top]]) {
                      //  cnt += num[top];
                      //  temp_visit[color[top]] = true;
                   // }
                    continue;
                }
                temp_visit[top] = true;
                visit[top] = true;
               // color[top] = now_color;
               // parent[top] = i;
                cnt++;
                for (int j = 0; j < v[top].size(); j++)
                    q.push(v[top][j]);
            }
            if (cnt > max_cnt){
                max_cnt = cnt;
                ans = i;
            }
           // num[i] = cnt;
            }
            
        }
        //for (int i = 1; i <= N; i++)
            //cout<<num[i]<<endl;
        cout<<"Case "<<ca<<": "<<ans<<endl;
    }
}


