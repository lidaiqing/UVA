#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int main()
{
    while(1)
    {
        int V;
        cin>>V;
        if (V == 0) break;
        vector <int> link[V+1];
        while(1)
        {
            int a,b;
            cin>>a>>b;
            if (a == 0 && b == 0) break;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        int color [V+1];
        memset(color,-1,sizeof(color));
        int source;
        for (int i = 1; i <= V; i++)
            if (link[i].size() != 0)
            {
                source = i;
                break;
            }
        queue <int> q;
        q.push(source);
        color[source] = 0;
        bool flag = true;
        while(!q.empty() && flag)
        {
            int top = q.front();
            q.pop();
            for (int i = 0; i < link[top].size(); i++)
            {
                int next = link[top][i];
                if (color[next] == -1)
                {
                    color[next] = 1 - color[top];
                    q.push(next);
                }
                else if (color[next] == color[top])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
