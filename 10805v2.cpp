#include <bits/stdc++.h>

using namespace std;
const int MAX = 700;
const int INF = 100000000;
int dist[MAX][MAX];

int main()
{
    int T;
    cin>>T;
    int cnt = 0;
    while (T--)
    {
        cnt++;
        int n,m;
        cin>>n>>m;
        int node = n;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (i != j) dist[i][j] = INF;
                else dist[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            dist[a][node] = 1;
            dist[node][a] = 1;
            dist[b][node] = 1;
            dist[node][b] = 1;
            node++;
        }
        for (int k = 0; k < n+m; k++)
            for (int i = 0; i < n+m; i++)
                for (int j = 0; j < n+m; j++)
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
        
        int ans = INF;
        for (int i = 0; i < n+m; i++)
        {
            int mx[2] = {};
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > mx[0])
                    mx[0] = dist[i][j];
                if (mx[0] > mx[1])
                    swap(mx[0],mx[1]);
            }
            ans = min(ans,mx[0] + mx[1]);
        }
        cout<<"Case #"<<cnt<<":"<<endl;
        cout<<ans/2<<endl;
        cout<<endl;
    }
}
