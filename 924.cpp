#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int E;
    cin>>E;
    vector <int> link[E];
    for (int i = 0; i < E; i++)
        link[i].clear();
    for (int i = 0; i < E; i++)
    {
        int N;
        cin>>N;
        for (int j = 0; j < N; j++)
        {
            int v;
            cin>>v;
            link[i].push_back(v);
        }
    }
    int T;
    cin>>T;
    while (T--)
    {
        int S;
        cin>>S;
        int dist[E];
        for (int i = 0; i < E; i++)
            dist[i] = 1000000;
        dist[S] = 0;
        queue <int> q;
        q.push(S);
        int mx_size = -1, mx_day;
        int num_cnt[2505];
        memset(num_cnt,0,sizeof(num_cnt));
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < link[u].size(); i++)
            {
                int v = link[u][i];
                if (dist[v] == 1000000)
                {
                    dist[v] = dist[u] + 1;
                    num_cnt[dist[v]]++;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < 2505; i++)
            if (num_cnt[i] > mx_size){
                mx_size = num_cnt[i];
                mx_day = i;
            }
        if (link[S].size() == 0) cout<<"0"<<endl;
        else cout<<mx_size<<" "<<mx_day<<endl;
    }
}
