#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
bool comp(pair<int,int> l, pair<int,int> r)
{
    return (l.first > r.first);
}
int main()
{
    int n;
    while (cin>>n)
    {
        int dist[n][n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) {
                    dist[i][j].cost = 0;
                    dist[i][j].num = 0;
                }
                else{
                    cin>>dist[i][j].cost;
                    dist[i][j].num = 1;
                }
            }
        }
        
        int parent[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                parent[i][j] = i;
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (dist[i][k].cost * dist[k][j].cost > dist[i][j].cost && dist[i][k].num + dist[k][j].num <= n){
                        dist[i][j].cost = dist[i][k].cost * dist[k][j].cost;
                        dist[i][j].num = dist[i][k].num + dist[k][j].num;
                      // if (i == j) cout<<i<<" "<<k<<" "<<j<<" "<<dist[i][j].cost<<" "<<dist[i][j].num<<endl;
                        parent[i][j] = parent[k][j];
                    }
                    else if (dist[i][k].cost * dist[k][j].cost == dist[i][j].cost && dist[i][k].num + dist[k][j].num < dist[i][j].num){
                        dist[i][j].num = dist[i][k].num + dist[k][j].num;
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
        int min_size = 1000000, min_ind;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = parent[i][i]; cnt <= n  && i != j; j = parent[i][j]){
                cnt++;
                cout<<j<<" ";
            }
            cout<<endl;
            for (int j = 0; j < n; j++)
            {
                cout<<i<<" "<<j<<" "<<dist[i][j].cost<<" ";
            }
            cout<<endl;
        }
    }
}
                
            
            
            
        

        
