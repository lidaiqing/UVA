#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int M,N;
char r_graph[25][50];
char letter;
int flood_fill_cnt(int r,int c,char c1,char c2)
{
    if (r_graph[r][c] != c1) return 0;
    //if (c - N >= 0 && r_graph[r][c-N] != c1) return 0;
   // if (c + N < W && r_graph[r][c+N] != c1) return 0;
    r_graph[r][c] = c2;
    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (cc == -1) cc = N - 1;
        else if (cc == N) cc = 0;
        if (rr >= 0 && rr < M && cc >= 0 && cc < N)
             cnt += flood_fill_cnt(rr,cc,c1,c2);
        
    }
    return cnt;
}
int main()
{
    while(cin>>M)
    {
        cin>>N;
        char o_graph[M][N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin>>o_graph[i][j];
        int X, Y;
        cin>>X>>Y;
        letter = o_graph[X][Y];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                r_graph[i][j] = o_graph[i][j];
        
        flood_fill_cnt(X,Y,letter,'.');
       // cout<<te<<endl;
        int mx = 0;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (r_graph[i][j] == letter){
                   // if (j - N >= 0 && r_graph[i][j-N] != letter) continue;
                   // if (j + N < W && r_graph[i][j+N] != letter) continue;
                    int temp = flood_fill_cnt(i,j,letter,'.');
                    mx = max(mx, temp);
                }
            }
        }
       /* for (int i = 0; i < N; i++){
            for (int j = 0; j < W; j++){
                cout<<r_graph[i][j];
            }cout<<endl;
        }*/

        cout<<mx<<endl;
    }
}

        
