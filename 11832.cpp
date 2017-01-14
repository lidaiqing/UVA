#include <bits/stdc++.h>

using namespace std;

#define MAX 80005
struct node {
    int first, second, third;
};
map<long long, bool> visit[45][MAX];

char path[45];
node parent[45][MAX][2];
char sign[45][MAX][2];
int N, F;
int value[45];
bool ok;
void build_path(int idx, int val, int s)
{
    //cout << idx << " " << val << endl;
    if (idx == 0 && val == 0) {
        if (path[idx] == 'x')
            path[idx] = sign[idx][val+40000][s];
        else if (sign[idx][val+40000][s] != path[idx])
        path[idx] = '?';
        return ;
    }
    build_path(parent[idx][val+40000][s].first, parent[idx][val+40000][s].second, parent[idx][val+40000][s].third);
    if (path[idx] == 'x')
            path[idx] = sign[idx][val+40000][s];
    else if (sign[idx][val+40000][s] != path[idx])
        path[idx] = '?';
    return;
}
long long ans;
void dfs(int idx, int val, long long state)
{
   // cout << idx << " " << val << " " << s << endl;
    if (visit[idx][val+40000][state]) {
        //build_path(idx,val,s);
        return;
    }
    visit[idx][val+40000][state] = true;
    if (idx == N-1) {
        if (val == F) {
            ok = true;
            if (ans == 0) {
                ans = state;
                for (int i = 0; i < N; i++)
                {
                    if (state & (1LL << i)) path[i] = '+';
                    else path[i] = '-';
                }
                //for (int i = 0; i < N; i++)
                  //  cout << path[i];
               // cout << endl;
            }
            else {
                for (int i = 0; i < N; i++)
                {
                    if (state & (1LL << i)) {
                        if (path[i] == '-') {
                            path[i] = '?';
                        }
                    }
                    else { 
                        if (path[i] == '+') {
                            path[i] = '?';
                        }
                    }
                }
            }
            //for (int i = 0; i < N; i++)
              //  if (state & (1LL << i)) cout << "1";
                //else cout << "0";
            //cout << endl;
            //build_path(idx, val, s);
        }
        return;
    }
    long long mask = (state | (1LL << (idx+1)));
    dfs(idx+1, val + value[idx+1], mask);
    mask ^= (1LL << (idx+1));
    dfs(idx+1, val - value[idx+1], mask);
}

void solve()
{
    //for (int i = 0; i < N; i++)
       // path[i] = 'x';
    //memset(visit,false,sizeof(visit));
    ok = false;
    ans = 0;
    dfs(0,value[0],1);
    dfs(0,-value[0],0);
    if (!ok) cout << "*" <<endl;
    else {
        for (int i = 0; i < N; i++)
            cout << path[i];
        cout << endl;
    }
}

int main()
{
    while (1)
    {
        cin >> N >> F;
        if (N == 0 && F == 0) break;
        for (int i = 0; i < N; i++)
            cin >> value[i];
        //value[0] = 0;
        solve();
    }
}

    
