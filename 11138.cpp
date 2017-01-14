#include <bits/stdc++.h>

using namespace std;

const int MAX = 505;

vector<int> match,vis;
vector<int> link[MAX];
int Aug(int l)
{
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < link[l].size(); j++)
    {
        int r = link[l][j];
        if (match[r] == -1 || Aug(match[r]))
        {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int T;
    cin>>T;
    int cnt = 0;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        cnt++;
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp;
                cin>>temp;
                if (temp == 1) {
                    link[i].push_back(n+j);
                }
            }
        }
        int MCBM = 0;
        int V = n + m;
        match.assign(V,-1);
        for (int l = 0; l < n; l++)
        {
            vis.assign(n,0);
            MCBM += Aug(l);
        }
        cout<<"Case "<<cnt<<": a maximum of "<<MCBM<<" nuts and bolts can be fitted together"<<endl;
    }
}
        

