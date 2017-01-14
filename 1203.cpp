#include <iostream>
#include <queue>
#include <stdio.h>
#include <map>
#include <vector>
#include <utility>

using namespace std;
typedef bool (*comp)(pair<int,int>,pair<int,int>);
bool compare(pair<int,int> l,pair<int,int> r)
{
    if(l.second>r.second)return true;
    else if(l.second==r.second)return l.first>r.first;
    else return false;
}
int main()
{

    map <int,int> mymap;
    priority_queue <pair<int,int>,vector<pair<int,int> >,comp> pq(compare);
    while(1)
    {

        string s;
        cin>>s;
        if(s=="#")break;
        int a,b;
        cin>>a>>b;

        mymap.insert(make_pair(a,b));

        pq.push(make_pair(a,b));
    }

    int k;
    cin>>k;
    while(k--)
    {

        pair<int,int> top=pq.top();
        pq.pop();
        cout<<top.first<<endl;

        pq.push(make_pair(top.first,top.second+mymap[top.first]));
    }
}

        
