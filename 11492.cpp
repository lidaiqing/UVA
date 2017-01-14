#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <functional>
#include <utility>

using namespace std;
struct node {
    string l1,l2;
    string word;
};
bool check(node s1,node s2)
{
    if ((s1.l1 == s2.l1) || (s1.l1 == s2.l2) || (s1.l2 == s2.l1) || (s1.l2 == s2.l2))
    {
        if (s1.word[0] != s2.word[0]) return true;
        return false;
    }
    else return false;
}

int main()
{
    while (1)
    {
        int M;
        cin>>M;
        if (M == 0) break;
        node word_list[M];
        int cost[M];
        string st,end;
        cin>>st>>end;
        for (int i = 0; i < M; i++)
        {
            cin>>word_list[i].l1>>word_list[i].l2>>word_list[i].word;
            cost[i] = word_list[i].word.size();
        }
        vector<int> link[M];
        for (int i = 0; i < M; i++){
            for (int j = i+1; j < M; j++){
                if (check(word_list[i],word_list[j])){
                    link[i].push_back(j);
                    link[j].push_back(i);
                }
            }
        }
        int dist[M];
        priority_queue <pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > pq;
        for (int i = 0; i < M; i++)
        {
            if (word_list[i].l1 == st || word_list[i].l2 == st)
            {
                dist[i] = cost[i];
                pq.push(make_pair(cost[i],i));
            }
            else
                dist[i] = 1000000;
        }
        int ans = -1;
        while (!pq.empty())
        {
            pair<int,int> front = pq.top();pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;
            if (word_list[u].l1 == end || word_list[u].l2 == end){
                if (ans != -1) ans = min(ans,dist[u]);
                else ans = dist[u];
            }
            for (int i = 0; i < link[u].size(); i++)
            {
                int v = link[u][i];
                if (dist[u] + cost[v] < dist[v]){
                    dist[v] = dist[u] + cost[v];
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        if (ans == -1) cout<<"impossivel"<<endl;
        else cout<<ans<<endl;
    }
}
        
        
                
            
