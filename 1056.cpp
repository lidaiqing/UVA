#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

int main()
{
    int cnt = 0;
    while (1)
    {
        cnt++;
        int P,R;
        cin>>P>>R;
        if (P == 0 && R == 0) break;
        
        int dist[P][P];
        for (int i = 0; i < P; i++){
            for (int j = 0; j < P; j++){
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = 1000000;
            }
        }
        map <string,int> mp;
        string name[P];
        int num_cnt = 0;
        for (int i = 0; i < R; i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            int u,v;
            if (mp.count(s1) == 0){
                mp.insert(make_pair(s1,num_cnt));
                u = num_cnt;
                num_cnt++;
            }
            else u = mp[s1];
            if (mp.count(s2) == 0){
                mp.insert(make_pair(s2,num_cnt));
                v = num_cnt;
                num_cnt++;
            }
            else v = mp[s2];
            dist[u][v] = 1;
            dist[v][u] = 1;
        }
        for (int k = 0; k < P; k++){
            for (int i = 0; i < P; i++){
                for (int j = 0; j < P; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        bool flag = true;
        int ans = -1;
        for (int i = 0; i < P; i++){
            for (int j = 0; j < P; j++){
                if (dist[i][j] == 1000000) flag = false;
                else ans = max(ans,dist[i][j]);
            }
        }
        cout<<"Network "<<cnt<<": ";
        if (flag) cout<<ans<<endl;
        else cout<<"DISCONNECTED"<<endl;
        cout<<endl;
    }
}


