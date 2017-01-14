#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <utility>
#include <string.h>

using namespace std;

int main()
{
    int cnt = 0;
    while (1)
    {
        cnt++;
        int NC;
        cin>>NC;
        if (NC == 0) break;
        int dist[100][100];
        for (int i = 0; i < 100; i++){
            for (int j = 0; j < 100; j++){
               if (i != j) dist[i][j] = 0;
               else dist[i][j] = 1;
            }
        }
        map <string,int> mp;
        string name[100];
        int total = 0;
       // bool sequ_check[100][100];
      //  memset(sequ_check,false,sizeof(sequ_check));
        while (NC--){
            int NE;
            cin>>NE;
            string temp;
            cin>>temp;
            int u;
            if (mp.count(temp) == 0){
                total++;
                mp.insert(pair<string,int>(temp,total-1));
                u = total - 1;
                name[u] = temp;
            }
            else u = mp[temp];
            
            for (int i = 0; i < NE-1; i++){
                string temp;
                cin>>temp;
                int v;
                if (mp.count(temp) == 0){
                    total++;
                    mp.insert(pair<string,int>(temp,total-1));
                    v = total - 1;
                    name[v] = temp;
                }
                else v = mp[temp];
                dist[u][v] = 1;
                u = v;
               // sequ_check[v][u] = true;
            }
        }
        int NM;
        cin>>NM;
        while (NM--)
        {
            string s1,s2;
            cin>>s1>>s2;
            int u ,v;
            if (mp.count(s1) == 0){
                total++;
                mp.insert(pair<string,int>(s1,total-1));
                u = total - 1;
                name[u] = s1;
            }
            else u = mp[s1];
            if (mp.count(s2) == 0){
                total++;
                mp.insert(pair<string,int>(s2,total-1));
                v = total - 1;
                name[v] = s2;
            }
            else v = mp[s2];
            dist[u][v] = 1;
        }
        int n = total;
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    dist[i][j] |= (dist[i][k] & dist[k][j]);
                }
            }
        }
        vector<pair<int,int> > ans;
        int num_cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (!dist[i][j] && !dist[j][i]){
                    num_cnt++;
                    ans.push_back(make_pair(i,j));
                }
            }
        }
        if (num_cnt == 0) printf("Case %d, no concurrent events.\n",cnt);
        else {
            printf("Case %d, %d concurrent events:\n",cnt,num_cnt);
            if (ans.size() >= 2){
                cout<<"("<<name[ans.back().first]<<","<<name[ans.back().second]<<") ";
                cout<<"("<<name[ans[0].first]<<","<<name[ans[0].second]<<") "<<endl;
            }
            else cout<<"("<<name[ans[0].first]<<","<<name[ans[0].second]<<") "<<endl;

        }
    }
}
                
                
        
