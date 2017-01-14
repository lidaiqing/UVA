#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
vector <int> link[205];
int dfs_low[205], dfs_num[205], dfs_parent[205];
int dfs_cnt;
vector <pair<int,int> > ans;
bool comp(pair<int,int> l,pair<int,int> r)
{
    if (l.first != r.first)
        return (l.first < r.first);
    else
        return (l.second < r.second);
}
void arti_bridge_find(int u)
{
    dfs_low[u] = dfs_num[u] = dfs_cnt++;
    
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        if (dfs_num[v] == -1)
        {
            dfs_parent[v] = u;
            arti_bridge_find(v);
            if (dfs_low[v] > dfs_num[u])
            {
                ans.push_back(make_pair(min(u,v),max(u,v)));
            }
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        }
        else if (dfs_parent[u] != v)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}
            
int main()
{
    int N;
    while(cin>>N)
    {
        cin.ignore();
        for (int i = 0; i < N; i++)
            link[i].clear();
        ans.clear();
        for (int i = 0; i < N; i++)
        {
            string s;
            getline(cin, s);
            int a, num, b;
            char blank;
            stringstream ss;
            ss.str(s);
            ss>>a;ss>>blank;
            ss>>num;
            ss>>blank;
            for (int j = 0; j < num; j++)
            {
                ss>>b;
                link[a].push_back(b);
                link[b].push_back(a);
               // cout<<a<<" "<<b<<endl;
            }
        }
        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,-1,sizeof(dfs_low));
        memset(dfs_parent,-1,sizeof(dfs_parent));
        dfs_cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (dfs_num[i] == -1)
            {
                arti_bridge_find(i);
            }
        }
        sort(ans.begin(),ans.end(),comp);
        cout<<ans.size()<<" critical links"<<endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i].first<<" - "<<ans[i].second<<endl;
        }
        cout<<endl;
    }
}
        


    
