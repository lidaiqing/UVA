#include <bits/stdc++.h>

using namespace std;

const int MAX = 300;

vector<int> vis,match;
vector<int> link[MAX];

int Aug(int l)
{
    if (vis[l]) return 0;
    vis[l] = true;
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
        vector<int> left,right;
        int n,m;
        cin>>n;
        cnt++;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            left.push_back(temp);
        }
        cin>>m;
        for (int i = 0; i < m; i++)
        {
            int temp;
            cin>>temp;
            right.push_back(temp);
        }
        for(int i = 0; i < MAX; i++)
            link[i].clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (left[i] != 0 && right[j] % left[i] == 0)
                    link[i].push_back(j+n);
                else if (right[j] == 0 && left[i] == 0)
                    link[i].push_back(j+n);
            }
        }
        int MCBM = 0;
        int V = n + m;
        match.assign(V,-1);
        for (int i = 0; i < n; i++)
        {
            vis.assign(n,0);
            MCBM += Aug(i);
        }
        cout<<"Case "<<cnt<<": "<<MCBM<<endl;
    }
}

