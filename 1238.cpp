#include <bits/stdc++.h>

using namespace std;
#define MAX 50
int N;
int sig[MAX];
int num[MAX];
bool visit[MAX][MAX][6000];
bool used[6000];
void dfs(int idx, int open, int val)
{
    if (visit[idx][open][val+3000]) return;
    visit[idx][open][val+3000] = true;
    if (idx == N) {
        used[val+3000] = true;
        return;
    }
    int nval = val + sig[idx] * num[idx] * ((open % 2 == 0) ? 1 : -1);//KEY part
    if (sig[idx] == -1) 
        dfs(idx + 1, open + 1, nval);
    if (open > 0)
        dfs(idx + 1, open - 1, nval);
    dfs(idx + 1, open, nval);
}
int main()
{
    string line;
    while(getline(cin, line)) 
    {
        stringstream ss(line);
        ss >> num[0];
        sig[0] = 1;
        int idx = 1;
        char temp;
        while (ss >> temp) {
            if (temp == '+') sig[idx] = 1;
            else sig[idx] = -1;
            ss >> num[idx];
            idx++;
        }
        N = idx;
        memset(visit,false,sizeof(visit));
        memset(used,false,sizeof(used));
        dfs(0, 0, 0);
        int ans = 0;
        for (int i = 0; i < 6000; i++)
            if (used[i]) ans++;
        cout << ans << endl;
    }
}

        
    
