#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    while (1)
    {
        int N;
        cin>>N;
        if (N == 0) break;
        int dist_y[30][30];
        int dist_m[30][30];
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (i == j) {
                    dist_y[i][j] = 0;
                    dist_m[i][j] = 0;
                }
                else {
                    dist_y[i][j] = 1000000;
                    dist_m[i][j] = 1000000;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            char a,b,c,d;
            int e;
            cin>>a>>b>>c>>d>>e;
            int u = c - 'A', v = d - 'A';
            if (a == 'Y'){
                dist_y[u][v] = min(dist_y[u][v],e);
                if (b == 'B') dist_y[v][u] = min(dist_y[v][u],e);
            }
            else if (a == 'M'){
                dist_m[u][v] = min(dist_m[u][v],e);
                if (b == 'B') dist_m[v][u] = min(dist_m[v][u],e);
            }
        }
        char s, e;
        int st_y,st_m;
        cin>>s>>e;
        st_y = s - 'A';
        st_m = e - 'A';
        
        for (int k = 0; k < 30; k++){
            for (int i = 0; i < 30; i++){
                for (int j = 0; j < 30; j++){
                    dist_y[i][j] = min(dist_y[i][j],dist_y[i][k] + dist_y[k][j]);
                    dist_m[i][j] = min(dist_m[i][j],dist_m[i][k] + dist_m[k][j]);
                }
            }
        }
        int ans = 1000000;
        vector<int> mi;
        for (int i = 0; i < 30; i++)
        {
            int sum = dist_y[st_y][i] + dist_m[st_m][i];
            if (sum < ans){
                ans = sum;
                mi.clear();
                mi.push_back(i);
            }
            else if (sum == ans){
                mi.push_back(i);
            }
            
        }
        sort(mi.begin(),mi.end());
       if (ans == 1000000) cout<<"You will never meet."<<endl;
       else {
           cout<<ans;
           for (int i = 0; i < mi.size(); i++){
               char temp = 'A' + mi[i];
               cout<<" "<<temp;
           }
           cout<<endl;
       }
    }
}
