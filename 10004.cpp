#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if (n == 0) break;
        int l;
        cin>>l;
        vector <int> link[n];
        for (int i = 0; i < l; i++)
        {
            int a,b;
            cin>>a>>b;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        queue <int> q;
        int color[n];
        memset(color,-1,sizeof(color));
        int source;
        for (int i = 0; i < n; i++)
            if (link[i].size() != 0){
                source = i;
                break;
            }
        bool flag = true;
        q.push(source);
        color[source] = 0;
        while(!q.empty() && flag)
        {
            int top = q.front();
            q.pop();
            for (int i = 0; i < link[top].size(); i++)
            {
                if (color[link[top][i]] == -1)
                {
                    color[link[top][i]] = 1 - color[top];
                    q.push(link[top][i]);
                }
                else if (color[link[top][i]] == color[top])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }
}
