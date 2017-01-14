#include<bits/stdc++.h>

using namespace std;
const int MAX = 205;
map<pair<int,int>,int> mp;
map<int,pair<int,int> > ret;
vector<pair<int,bool> > link[MAX];
list<int> cyc;

void EulerTour(list<int>::iterator i, int u)
{
    //cout<<u<<endl;
    for (int j = 0; j < link[u].size(); j++)
    {
        pair<int, bool> v = link[u][j];
        if (v.second) {
            link[u][j].second = false;
            for (int k = 0; k < link[v.first].size(); k++)
            {
                pair<int,bool> uu = link[v.first][k];
                if (uu.first == u && uu.second)
                {
                    link[v.first][k].second = false;
                    break;
                }
            }
           // cout<<"asd"<<u<<endl;
            EulerTour(cyc.insert(i, u), v.first);
        }
    }
}
            
int dist(int x1,int y1,int x2,int y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int degree[MAX];
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int x1,y1,x2,y2;
        string s;
        double dist1 = 0;
        cin>>x1>>y1;
        cin.ignore();
        while (getline(cin,s))
        {
            if (s == "") break;
            istringstream ss (s);
            ss>>x1>>y1>>x2>>y2;
            dist1 += dist(x1,y1,x2,y2);
        }
        dist1 *= 2;
        dist1 /= 1000;
        int hour, mins;
        double Time = dist1 / 20;
        Time *= 60;
        Time = round(Time);
        hour = Time / 60;
        mins = (int)(Time) % 60;
        printf("%d:%02d\n", hour, mins);
        if (T != 0) cout<<endl;
    }
}

        



