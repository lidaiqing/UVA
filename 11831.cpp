#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main()
{

    while(1)
    {
        int N, M, S;
        cin>>N>>M>>S;
        if (N==0 && M==0 && S==0) break;
        char mp[N+1][M+1];
        char face;
        int cur_row, cur_col;
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                cin>>mp[i][j];
                if (mp[i][j] != '.' && mp[i][j] != '*' && mp[i][j] != '#')
                {
                    face = mp[i][j];
                    cur_row = i;
                    cur_col = j;
                }
            }
        }
        int ans = 0;
        
        for (int i = 0;i < S; i++)
        {
            char ins;
            cin>>ins;
            
            if (ins == 'D') {
                if (face == 'N') face = 'L';
                else if (face == 'L') face = 'S';
                else if (face == 'S') face = 'O';
                else face = 'N';
            }
            else if (ins == 'E') {
                if (face == 'N') face = 'O';
                else if (face == 'O') face = 'S';
                else if (face == 'S') face = 'L';
                else face = 'N';
            }
            else {
                if (face == 'N'){
                    if (cur_row - 1 >= 1 && mp[cur_row-1][cur_col] != '#')
                        cur_row = cur_row - 1;
                }
                else if (face == 'L'){
                    if (cur_col + 1 <= M && mp[cur_row][cur_col+1] != '#')
                        cur_col = cur_col + 1;
                }
                else if (face == 'O'){
                    if (cur_col - 1 >= 1  && mp[cur_row][cur_col-1] != '#')
                        cur_col = cur_col - 1;
                }
                else {
                    if (cur_row + 1 <= N && mp[cur_row+1][cur_col] != '#')
                        cur_row = cur_row + 1;
                }
            }
            if (mp[cur_row][cur_col] == '*') {
                ans += 1;
                mp[cur_row][cur_col] = '.';
            }
        }
        cout<<ans<<endl;
    }
}

