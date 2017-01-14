#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

const int MAX = 38;
const int INF = 100000;

int res[MAX][MAX], mf, f, s, t;
vector<int> p;

void augment(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    }
    else if (p[v] != -1)
    {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main()
{
    
    while (1)
    {
        mf = 0;
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                res[i][j] = 0;
        s = 0, t = 37;
        for (int i = 27; i <= 36; i++)
            res[i][t] = 1;
        string ss;
        int cnt = 0;
        if (!getline(cin,ss)) break;
        do {
            if (ss == "") break;
            int ind, num;
            ind = ss[0] - 'A' + 1;
            num = ss[1] - '0';
            res[s][ind] = num;
            cnt += num;
           // cout<<ind<<" "<<num<<endl;
            for (int i = 3; i < ss.size()-1; i++)
            {
                int com = ss[i] - '0' + 27;
                res[ind][com] = INF;
            }
        } while(getline(cin,ss));
        

        while (1) {
            f = 0;
            vector<int> dist(MAX,INF);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(MAX,-1);
            while (!q.empty())
            {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v = 0; v < MAX; v++)
                {
                    if (res[u][v] > 0 && dist[v] == INF)
                    {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        p[v] = u;
                    }
                }
            }
            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }
        if (mf != cnt) cout<<"!"<<endl;
        else {
            for (int i = 27; i <= 36; i++)
            {
                bool flag = false;
                for (int j = 1; j <= 26 && !flag; j++)
                {
                    if (res[i][j] > 0){
                        char ch = j - 1 + 'A';
                        cout<<ch;
                        flag = true;
                    }
                }
                if (!flag) cout<<"_";
            }
            cout<<endl;
        }
    }
}
        
