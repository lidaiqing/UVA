#include <bits/stdc++.h>

using namespace std;
#define INF 10000000
struct node {
    vector<int> list;
    int dist;
};

bool is_prime(int n)
{
    if (n == 0) return false;
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;
    return true;
}
bool check(vector<int> v)
{
    for (int i = 0; i < 8; i++)
        if (abs(v[i]) != i + 1)
            return false;
    return true;
}
node st;
void solve()
{
    int ans = INF;
    queue <node> q;
    q.push(st);
    map<vector<int>, bool> visit;
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
       // cout << u.dist << endl;
        //for (int i = 0; i < 8; i++)
          //  cout << u.list[i] << " ";
        //cout << endl;
        if (visit[u.list]) continue;
        visit[u.list] = true;
        if (check(u.list)) ans = min(ans,u.dist);
        for (int i = 0; i < 8; i++)
        {
                for (int j = i + 1; j < 8; j++)
                {
                    if (u.list[i] > 0 && u.list[j] > 0) continue;
                    if (u.list[i] < 0 && u.list[j] < 0) continue;
                    if (is_prime(abs(u.list[i]) + abs(u.list[j]))) {
                        node temp;
                       // cout << u.list[i] << " " << u.list[j] << endl;
                        for (int k = 0; k < 8; k++)
                            temp.list.push_back(u.list[k]);
                        temp.dist = u.dist + 1;
                        int v = temp.list[j];
                        temp.list.erase(temp.list.begin()+j);
                        temp.list.insert(temp.list.begin()+i,v);
                        q.push(temp);
                        //if (j != i + 1) {
                            temp.list.erase(temp.list.begin()+i);
                            temp.list.insert(temp.list.begin()+i+1,v);
                            q.push(temp);
                        
                        temp.list.clear();
                        for (int k = 0; k < 8; k++)
                            temp.list.push_back(u.list[k]);
                        v = temp.list[i];
                        temp.list.insert(temp.list.begin()+j,v);
                        temp.list.erase(temp.list.begin()+i);
                        q.push(temp);
                        temp.list.erase(temp.list.begin()+j-1);
                        temp.list.insert(temp.list.begin()+j,v);
                        q.push(temp);
                    }
                }
        }
    }
    if (ans == INF) cout << "-1" << endl;
    else cout << ans << endl;
}

int main()
{
    int case_num = 0;
    while (1) {
        case_num++;
        st.list.clear();
        for (int i = 0; i < 8; i++)
        {
            int temp;
            cin >> temp;
            if (temp == 0) return 0;
            st.list.push_back(temp);
        }
        st.dist = 0;
        cout << "Case " << case_num << ": ";
        solve();
    }
}
