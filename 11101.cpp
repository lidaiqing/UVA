#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;
int dist[2005][2005];
int main()
{
    int p1,p2;
    while (1)
    {
        vector <pair<int,int> > m1;
        set <pair<int,int> > m2;
        cin>>p1;
        if (p1 == 0) break;
        int max_x = -1,max_y = -1;
            for (int i = 0; i < p1; i++)
            {
                int x,y;
                cin>>x>>y;
                max_x = max(max_x,x);
                max_y = max(max_y,y);
                m1.push_back(make_pair(x,y));
            }
        
        cin>>p2;
        for (int i = 0; i < p2; i++)
        {
            int x,y;
            cin>>x>>y;
            max_x = max(max_x,x);
            max_y = max(max_y,y);
            m2.insert(make_pair(x,y));
        }
        int ans = 10000000;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        
            memset(dist,-1,sizeof(dist));
            
            queue <pair<int,int> > q;
            for (int i = 0; i < p1; i++){
                dist[m1[i].first][m1[i].second] = 0;
                q.push(m1[i]);
            }
            while (!q.empty())
            {
                pair<int,int> u = q.front();//cout<<u.first<<" "<<u.second<<endl;
                q.pop();
                if (m2.count(u) != 0){
                   ans = min(ans,dist[u.first][u.second]);
                   break;
                }
    
                for (int j = 0; j < 4; j++)
                {
                    int xx = u.first + dx[j];
                    int yy = u.second + dy[j];
                    if (xx >= 0 && xx <= max_x && yy >= 0 && yy <= max_y && dist[xx][yy] == -1){
                        dist[xx][yy] = dist[u.first][u.second] + 1;
                        q.push(make_pair(xx,yy));
                    }
                }
            }
        
        cout<<ans<<endl;
    }
}
                    
            

