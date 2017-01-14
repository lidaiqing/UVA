#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <string>

using namespace std;
string name[30];
map <string,int> name_to_num;
vector <int> link[30];
int dfs_num[30], dfs_low[30];
bool visit[30];
int dfs_cnt, set_cnt;
vector <int> S;

void dfs_scc_print(int u) {
    dfs_low[u] = dfs_num[u] = dfs_cnt++;
    S.push_back(u);
    visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        if (dfs_num[v] == -1)
            dfs_scc_print(v);
        if (visit[v])
            dfs_low[u] = min (dfs_low[u], dfs_low[v]);
    }
    
    if (dfs_low[u] == dfs_num[u]) {
        while (1) {
            int v = S.back();
            S.pop_back();
            visit[v] = false;
            if (u != v) cout<<name[v]<<", ";
            else {
                cout<<name[v]<<endl;
                break;
            }
            
        }
    }
}
            
    
int main()
{
    set_cnt = 0;
    while(1)
    {
        int n,m;
        cin>>n>>m;
        if (n == 0 && m == 0) break;
        if (set_cnt != 0) cout<<endl;
        int num_cnt = 0;
        for (int i = 0; i < n; i++)
            link[i].clear();
        for (int i = 0; i < n; i++)
            name[i].clear();
        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,-1,sizeof(dfs_low));
        memset(visit,-1,sizeof(visit));
        S.clear();
        name_to_num.clear();
        for (int i = 0; i < m; i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            if (!name_to_num.count(s1)){
                name_to_num[s1] = num_cnt;
                name[num_cnt].append(s1);
                num_cnt++;
            }
            if (!name_to_num.count(s2)){
                name_to_num[s2] = num_cnt;
                name[num_cnt].append(s2);
                num_cnt++;
            }
            int n1,n2;
            n1 = name_to_num[s1];
            n2 = name_to_num[s2];
            link[n1].push_back(n2);
        }
      //  for (int i = 0; i < n; i++)
        //    cout<<name[i]<<endl;
        dfs_cnt = 0;
        set_cnt++;
        cout<<"Calling circles for data set "<<set_cnt<<":"<<endl;

        for (int i = 0; i < n; i++)
        {
            if (dfs_num[i] == -1){
                dfs_scc_print(i);
            }
        }
    }
}
        
            
