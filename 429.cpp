#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#include <sstream>

using namespace std;
bool check (string s1,string s2)
{
    int diff = 0;
    if (s1.length() != s2.length()) return false;
    int len = s1.length();
    for (int i = 0; i < len; i++)
    {
        if (s1[i] != s2[i])
            diff++;
    }
    if (diff >= 2) return false;
    return true;
}
int main()
{
    int N;
    cin>>N;
    while (N--)
    {
        map <string,int> dict;
        vector <string> name;
        int cnt = 0;
        while (1) {
            string temp;
            cin>>temp;
            if (temp == "*") break;
            dict[temp] = cnt++;
            name.push_back(temp);
        }
        vector <int> link[cnt];
        for (int i = 0; i < cnt; i++)
        {
            for (int j = i+1; j < cnt; j++)
            {
                if (check(name[i],name[j])){
                    link[i].push_back(j);
                    link[j].push_back(i);
                }
            }
        }
        cin.ignore();
        string s1s2;
        while (getline(cin,s1s2))
        {
            if (s1s2 == "") break;
            istringstream ss(s1s2);
            string s1,s2;
            ss>>s1>>s2;
        
            int dist[cnt];
            for (int i = 0; i < cnt; i++)
                dist[i] = 1000000;
            dist[dict[s1]] = 0;
            queue <int> q;
            q.push(dict[s1]);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int i = 0; i < link[u].size(); i++)
                {
                    int v = link[u][i];
                    if (dist[v] == 1000000)
                    {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            cout<<s1<<" "<<s2<<" "<<dist[dict[s2]]<<endl;
        }
        if (N != 0) cout<<endl;
    }
}
