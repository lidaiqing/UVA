#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int v,e;
        cin>>v>>e;
        vector <int> link[v];
    
        for (int i = 0; i < e; i++)
        {
            int f,t;
            cin>>f>>t;
            link[f].push_back(t);
            link[t].push_back(f);
        }
        int color[v];
        memset(color,-1,sizeof(color));
        int cnt = 0;
        bool flag = true;
        for (int i = 0; i < v && flag; i++){
            if (color[i] == -1){
        int source = i;
        int temp_cnt = 0;
        int node_cnt = 0;
    
        queue <int> q;
        color[source] = 0;
        q.push(source);
        while(!q.empty() && flag)
        {
            int top = q.front();
            q.pop();
            node_cnt++;
            if (color[top] == 0) temp_cnt++;
            for (int i = 0; i < link[top].size(); i++)
            {
                int ne = link[top][i];
                if (color[ne] == -1){
                    color[ne] = 1 - color[top];
                    q.push(ne);
                }
                else if (color[ne] == color[top])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (min(temp_cnt, node_cnt - temp_cnt) == 0) cnt += 1;
        else cnt += min(temp_cnt,node_cnt - temp_cnt);
            }
        }
        if (!flag) cout<<"-1"<<endl;
        else cout<<cnt<<endl;
    }
}

