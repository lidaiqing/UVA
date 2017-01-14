#include <bits/stdc++.h>

using namespace std;
const int MAX = 2505;
const int INF = 100000000;
vector<int> link[MAX];
int x,y;
int mx;
int path[MAX];
void dfs(int u,int p,int len,int stat)
{
    if (mx < len) {
        mx = len;
        if (stat == 0) x = u;
        else y = u;
    }
   // cout<<u<<endl;
    for (int i = 0; i < link[u].size(); i++)
    {
        int v = link[u][i];
        if (v != p){
            path[v] = u;
            dfs(v,u,len+1,stat);
        }
    }
}

    
int main()
{
    int N;
    cin>>N;
    while (N--)
    {
        int n;
        cin>>n;
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        for (int i = 1; i <= n-1; i++)
        {
            int a,b;
            cin>>a>>b;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        bool visit[MAX][MAX];
        memset(visit,false,sizeof(visit));
        int ans = INF;
        int cut[2];
        int build[2];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < link[i].size(); j++)
            {
                int v = link[i][j];
                if (!visit[i][v] && !visit[v][i])
                {
                    visit[i][v] = true;
                    visit[v][i] = true;
                    for (int k = 0; k < link[i].size(); k++)
                        if (link[i][k] == v) {
                            link[i].erase(link[i].begin()+k);
                            break;
                        }
                    for (int k = 0; k < link[v].size(); k++)
                        if (link[v][k] == i) {
                            link[v].erase(link[v].begin()+k);
                            break;
                        }
                    
                    int diameter1, diameter2;
                    mx = -1;
                    dfs(i,0,0,0);
                    mx = -1;
                    memset(path,-1,sizeof(path));
                    dfs(x,0,0,1);
                    vector<int> p;
                    for (int k = y; k != -1; k = path[k])
                        p.push_back(k);
                    int center1,center2;
                    int mid = p.size() / 2;
                    center1 = p[mid];
                    diameter1 = mx;
        
                    mx = -1;
                    dfs(v,0,0,0);
                    mx = -1;
                    memset(path,-1,sizeof(path));
                    dfs(x,0,0,1);
                    p.clear();
                    for (int k = y; k != -1; k = path[k])
                        p.push_back(k);
                    center2 = p[p.size()/2];
                    diameter2 = mx;
                    mx = -1;
                    //cout<<"asd"<<endl;
                    link[center1].push_back(center2);
                    link[center2].push_back(center1);
                    mx = -1;
                    dfs(i,0,0,0);
                    mx = -1;
                    dfs(x,0,0,1);
                    int diameter3 = mx;
                    int temp = max(diameter1,max(diameter2,diameter3));
                    if (temp < ans) {
                        ans = temp;
                        cut[0] = i;
                        cut[1] = v;
                        build[0] = center1;
                        build[1] = center2;
                    }
                    link[center1].pop_back();
                    link[center2].pop_back();
                    link[i].push_back(v);
                    link[v].push_back(i);
                    //cout<<i<<" "<<v<<" "<<diameter1<<" "<<diameter2<<" "<<diameter3<<endl;
                }
            }
        }
        cout<<ans<<endl;
        cout<<cut[0]<<" "<<cut[1]<<endl;
        cout<<build[0]<<" "<<build[1]<<endl;

     }
}
