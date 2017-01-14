#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
    int r,c;
};

string GetBinaryStringFromHexString (char sHex[], int length)
		{
			string sReturn = "";
			for (int i = 0; i < length; ++i)
			{
				switch (sHex [i])
				{
					case '0': sReturn.append ("0000"); break;
					case '1': sReturn.append ("0001"); break;
					case '2': sReturn.append ("0010"); break;
					case '3': sReturn.append ("0011"); break;
					case '4': sReturn.append ("0100"); break;
					case '5': sReturn.append ("0101"); break;
					case '6': sReturn.append ("0110"); break;
					case '7': sReturn.append ("0111"); break;
					case '8': sReturn.append ("1000"); break;
					case '9': sReturn.append ("1001"); break;
					case 'a': sReturn.append ("1010"); break;
					case 'b': sReturn.append ("1011"); break;
					case 'c': sReturn.append ("1100"); break;
					case 'd': sReturn.append ("1101"); break;
					case 'e': sReturn.append ("1110"); break;
					case 'f': sReturn.append ("1111"); break;
				}
			}
			return sReturn;
		}
int H, W;
string r_graph[205];
int len; 
int dr[] = {-1, 1,0,0};
int dc[] = {0,0,-1,1};
int color[205][500];
bool visit[205][500];
void flood_fill_first(int r,int c,int col)
{
    if (visit[r][c]) return;
    visit[r][c] = true;
    color[r][c] = col;
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr >= 0 && rr < H && cc >= 0 && cc < len && r_graph[rr][cc] == r_graph[r][c])
            flood_fill_first(rr,cc,col);
    }
}
bool check(int r,int c)
{
    queue <node> q;
    node st;
    st.r = r;
    st.c = c;
    q.push(st);

    bool vvisit[205][500];
    memset(vvisit,false,sizeof(vvisit));
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        if (top.r == 0 || top.r == H-1 || top.c == 0 || top.c == len-1)
            return false;
        //cout<<top.r<<" "<<top.c<<endl;
        if (vvisit[top.r][top.c]) continue;
        vvisit[top.r][top.c] = true;
        for (int i = 0; i < 4; i++)
        {
            int rr = top.r + dr[i];
            int cc = top.c + dc[i];
            if (rr >= 0 && rr < H && cc >= 0 && cc < len)
            {   
                if (r_graph[r][c] == r_graph[rr][cc])
                {
                    node temp;
                    temp.r = rr;
                    temp.c = cc;
                    q.push(temp);
                }
            }
        }
    }
    return true;


}



int flood_fill_cnt(int r,int c)
{
    int cnt = 0;
    queue <node> q;
    node st;
    st.r = r;
    st.c = c;
    q.push(st);

    bool vvisit[205][500];
    memset(vvisit,false,sizeof(vvisit));
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        //cout<<top.r<<" "<<top.c<<endl;
        if (vvisit[top.r][top.c]) continue;
        vvisit[top.r][top.c] = true;
        for (int i = 0; i < 4; i++)
        {
            int rr = top.r + dr[i];
            int cc = top.c + dc[i];
            if (rr >= 0 && rr < H && cc >= 0 && cc < len)
            {   
                if(r_graph[rr][cc] == r_graph[r][c])
                {  // cout<<rr<<" "<<cc<<endl;
                   // cout<<r_graph[rr][cc]<<"adas"<<endl;
                    node temp;
                    temp.r = rr;
                    temp.c = cc;
                    q.push(temp);
                }
                else if (color[rr][cc] == -1 && check(rr,cc))
                {
                   // cout<<rr<<" "<<cc<<endl;
                    cnt++;
                    flood_fill_first(rr,cc,cnt);
                }
            }
        }
    }
    return cnt;
}

    
int main()
{
    int cnt = 0;
    while(1)
    {
        cin>>H>>W;
        if (H == 0 && W == 0) break;
        cnt++;
        char o_graph[H][W];
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin>>o_graph[i][j];
        for (int i = 0; i < H; i++)
        {
            r_graph[i] = GetBinaryStringFromHexString (o_graph[i], W);
        }
        len = r_graph[0].length();
        memset(color, -1, sizeof(color));
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < len; i++)
        {
            if (r_graph[0][i] == '0') {
                flood_fill_first(0, i, 0);
                break;
            }
        }
        /*for (int i = 0; i < H; i++){
            for (int j =0; j < len; j++){
                cout<<r_graph[i][j];
            }cout<<endl;
        }*/

        vector <char> ans;
        int black = -1;
        for (int i = 0; i < H; i++){
            for (int j = 0; j < len; j++){
                if (r_graph[i][j] == '1' && color[i][j] == -1){
                    black--;
                    flood_fill_first(i,j,black);

                    int temp = flood_fill_cnt(i,j);
                    if (temp == 0) ans.push_back('W');
                    else if (temp == 1) ans.push_back('A');
                    else if (temp == 2) ans.push_back('K');
                    else if (temp == 3) ans.push_back('J');
                    else if (temp == 4) ans.push_back('S');
                    else ans.push_back('D');
                }
            }
        }
        /*for (int i = 0; i < H; i++){
            for (int j =0; j < len; j++){
                cout<<color[i][j];
            }cout<<endl;
        }*/

        sort(ans.begin(),ans.end());
        cout<<"Case "<<cnt<<": ";
        for (int i = 0; i < ans.size(); i++)
            cout<<ans[i];
        cout<<endl;
    }



    


}
