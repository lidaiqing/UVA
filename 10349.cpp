#include <bits/stdc++.h>

using namespace std;

const int MAX = 405;
vector<int> match,vis;
vector<int> link[MAX];
int Aug(int l) {
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
    while (T--)
    {
        int h,w;
        cin>>h>>w;
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        vector<pair<int,int> > left,right;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char temp;
                cin>>temp;
                if (temp == '*') {
                    if ((i + j) % 2 != 0) 
                        left.push_back(make_pair(i,j));
                    else
                        right.push_back(make_pair(i,j));
                }
            }
        }
        int n = left.size(), m = right.size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int rr = left[i].first + dr[k];
                    int cc = left[i].second + dc[k];
                    if (rr == right[j].first && cc == right[j].second)
                    {
                        link[i].push_back(n+j);
                    }
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
        int ans = V - MCBM;
        cout<<ans<<endl;
    }
}
