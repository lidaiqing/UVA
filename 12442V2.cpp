#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int con[50005];
bool visit[50005];
int sum[50005];

int dfs(int u)
{
    int v = con[u];
    visit[u] = true;
    if (!visit[v]) sum[u] = 1 + dfs(v);
    else {
        visit[u] = false;
        return 0;
    }
    visit[u] = false;
    return sum[u];
}
    
int main()
{
    int T;
    cin>>T;
    int cnt = 0;
    while(T--)
    {
        cnt++;
        int N;
        cin>>N;
        for (int i = 0; i < N; i++)
        {
            int u,v;
            cin>>u>>v;
            con[u] = v;
        }
        memset(visit, false, sizeof(visit));
        memset(sum, 0, sizeof(sum));
        int mx = -1, ans;
        for (int i = 1; i <= N; i++)
        {
            if (sum[i] == 0) dfs(i);
            if (sum[i] > mx){
                mx = sum[i];
                ans = i;
            }
        }
        cout<<"Case "<<cnt<<": "<<ans<<endl;
    }
}


