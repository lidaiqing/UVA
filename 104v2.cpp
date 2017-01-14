#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <string.h>

using namespace std;
int p[25][25][25];
void print_path(int i,int j,int s)
{
    if (s == 0)
    {
        cout<<i+1;
        return;
    }
    print_path(i,p[s][i][j],s-1);
    cout<<" "<<j+1;
    return;
}
int main()
{
    int n;
    while (cin>>n)
    {
        memset(p,0,sizeof(p));
        double dist[n+1][n][n];
        memset(dist,0,sizeof(dist));
        
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                   if (i == j) dist[1][i][j] = 1.0;
                }
            }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j){
                    double temp;
                    cin>>temp;
                    dist[1][i][j] = temp;
                }
            }
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[1][i][j] = j;
        bool flag = false;
        int ind, len;
        for (int l = 2; l <= n && !flag; l++){
            for (int k = 0; k < n && !flag; k++){
                for (int i = 0; i < n && !flag; i++){
                    for (int j = 0; j < n && !flag; j++){
                        if (dist[l-1][i][k] * dist[1][k][j] > dist[l][i][j])
                        {
                            dist[l][i][j] = dist[l-1][i][k] * dist[1][k][j];
                            p[l][i][j] = k;
                        }
                        for (int ii = 0; ii < n; ii++){
                        if (dist[l][ii][ii] > 1.01){
                            flag = true;
                            ind = ii;
                            len = l;
                            break;
                        }  
                        }
                    }
                }
            }
        }
        if (!flag) cout<<"no arbitrage sequence exists"<<endl;
        else {
            print_path(ind,ind,len);
            cout<<endl;
        }


    }
}
