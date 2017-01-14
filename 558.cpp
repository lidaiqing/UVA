#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int c;
    cin>>c;
    while (c--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> link[n];
        int cost[n][n];
        for (int i = 0; i < m; i++)
        {
            int x,y,t;
            cin>>x>>y>>t;
            link[x].push_back(y);
            cost[x][y] = t;
        }
        int dist[n];
        for (int i = 0; i < n; i++)
            dist[i] = 1000000;
        dist[0] = 0;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n; j++){
                for (int k = 0; k < link[j].size(); k++){
                    int u = j, v = link[j][k];
                    if (dist[u] + cost[u][v] < dist[v])
                        dist[v] = dist[u] + cost[u][v];
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < n && !flag; i++){
            for (int j = 0; j < link[i].size() && !flag; j++){
                int u = i, v = link[i][j];
                if (dist[u] + cost[u][v] < dist[v]){
                    flag = true;
                }
            }
        }
        if (!flag) cout<<"not possible"<<endl;
        else cout<<"possible"<<endl;
    }
}
