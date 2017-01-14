#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;
const int INF = 1000000;
int degree[MAX];
vector<pair<int,bool> > link[MAX];
list<int> cyc;
void EulerTour(list<int>::iterator i, int u)
{
    for (int j = 0; j < link[u].size(); j++)
    {
        pair<int,bool> v = link[u][j];
        if (v.second) {
            link[u][j].second = 0;
            for (int k = 0; k < link[v.first].size(); k++)
            {
                pair<int,bool> uu = link[v.first][k];
                if (uu.first == u && uu.second)
                {
                    link[v.first][k].second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(i,u), v.first);
        }
    }
}
bool check()
{
    for (int i = 0; i < MAX; i++)
        if (degree[i] % 2 != 0)
            return false;
    return true;
}
int main()
{
    int T;
    cin>>T;
    int cnt = 0;
    while (T--)
    {
        cnt++;
        cyc.clear();
        int N;
        cin>>N;
        memset(degree,0,sizeof(degree));
        for (int i = 0; i < MAX; i++)
            link[i].clear();
        int st;
        for (int i = 0; i < N; i++)
        {
            int a,b;
            cin>>a>>b;
            st = a;
            link[a].push_back(make_pair(b,1));
            link[b].push_back(make_pair(a,1));
            degree[a]++;
            degree[b]++;
        }
        cout<<"Case #"<<cnt<<endl;
        if (!check())
        {
            cout<<"some beads may be lost"<<endl;
        }
        else
        {
            EulerTour(cyc.begin(),st);
            //cout<<cyc.size()<<endl;
            list<int>::iterator pre = cyc.begin();
            list<int>::iterator it = cyc.begin();
            it++;
            for (; it != cyc.end(); it++)
            {
                cout<<*pre<<" "<<*it<<endl;
                pre = it;
            }
            cout<<*pre<<" "<<cyc.front()<<endl;
        }
        if (T != 0) cout<<endl;
    }
}
