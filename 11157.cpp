#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
int main()
{

    int t;
    cin>>t;
    int cnt = 0;
    while(t--)
    {
        cnt++;
        ll n, d;
        cin>>n>>d;
        bool visit[n+1];
        memset(visit,false,sizeof(visit));
        vector <pair<char, ll> > v;
        v.push_back(make_pair('B',0));
        for(int i=0; i<n;i++)
        {
            string temp;
            cin>>temp;
            v.push_back(make_pair(temp[0],temp[2]-'0'));
        }
        v.push_back(make_pair('B',d));
        ll ans = 0;
        int pos=0;
        while(pos!=v.size())
        {
            if(pos == v.size()-1) break;
    
            if(v[pos+1].first == 'B')
            {
                
                ans = max(ans, v[pos+1].second - v[pos].second);
                pos++;
            }
            else
            {
                if(pos + 2 < v.size())
                {
                    if(v[pos+2].first == 'S')
                    {
                        visit[pos+2] = true;
                        ans = max(ans, v[pos+2].second - v[pos].second);
                        pos = pos + 2;
                    }
                    else
                    {
                        ans = max(ans, v[pos+2].second - v[pos].second);
                        pos = pos +2;
                    }
                }
            }

        }
        pos=0;
        while(pos!=v.size())
        {
            if(v[pos+1].first == 'B')
            {
                ans = max(ans, v[pos+1].second - v[pos].second);
                pos++;
            }
            else
            {
                if(visit[pos+1])
                {
                    pos++;
                    continue;
                }
                else {
                    ans = max(ans, v[pos+1].second - v[pos].second);
                    pos++;
                }
            }
        }

        cout<<"Case "<< cnt<<": ";
        cout << ans << endl;
    }
}
                    


        

