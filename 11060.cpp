#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <functional>

using namespace std;

map <string,int> mp;
vector <int> link[105];
vector <int> ans;
bool visit[105];

void dfs_top(int u, int num)
{
    visit[u] = true;
    for (int i = 0; i < link[u].size(); i++)
    {
        if (!visit[link[u][i]]) dfs_top(link[u][i],num);
    }
    ans.push_back(u);
}

int main()
{
    int N;
    int cnt = 0;
    while(cin>>N)
    {
        cnt++;
        mp.clear();
        ans.clear();
        for (int i = 0; i < 105; i++)
        {
            link[i].clear();
        }
        string name[N];
        int in[N];

        for (int i = 0; i < N; i++)
        {
            string temp;
            cin>>temp;
            name[i].append(temp);
            mp[temp] = i;
            in[i] = 0;
        }
        int M;
        cin>>M;
        for (int i = 0; i < M; i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            link[mp[s1]].push_back(mp[s2]);
            in[mp[s2]] += 1;
        }
        
        memset(visit, false, sizeof (visit));
        priority_queue <int,vector<int>,greater<int> > q;
        for (int i = 0; i < N; i++)
            if (in[i] == 0) {
                q.push(i);
            }
        while(!q.empty())
        {
            int top = q.top();
            q.pop();
            //if (visit[top]) continue;
            //visit[top] = true;
            ans.push_back(top);
            for (int i = 0; i < link[top].size(); i++)
            {
                in[link[top][i]]--;
                if (in[link[top][i]] == 0){
                    q.push(link[top][i]);
                }
                link[top].erase(link[top].begin() + i);
                i--;
            }
        }
        

          
        cout<<"Case #"<<cnt<<": Dilbert should drink beverages in this order:";

        for (int i = 0; i < N; i++)
            cout<<" "<<name[ans[i]];
        cout<<"."<<endl;
        cout<<endl;
    }
}
