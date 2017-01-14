#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int N;
char mp[105][105];

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
void flood_fill(int r,int c,char c1,char c2,char c3)
{
    if (mp[r][c] != c1 && mp[r][c] != c2) return ;
    mp[r][c] = c3;
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr >= 0 && rr < N && cc >= 0 && cc < N)
            flood_fill(rr,cc,c1,c2,c3);
    }
}
int main()
{
    int T;
    cin>>T;
    int te = 0;
    while(T--)
    {
        te++;
        cin>>N;
        for (int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin>>mp[i][j];
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mp[i][j] == 'x'){
                    cnt++;
                    flood_fill(i,j,'x','@','#');
                }
            }
        }

        cout<<"Case "<<te<<": "<<cnt<<endl;
    }
}
        
