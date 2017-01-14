#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    vector <int> v;
    int temp;
    while(cin>>temp)
    {
        v.push_back(temp);
        sort(v.begin(),v.end());
        if(v.size()%2!=0)
        {
            cout<<v[(v.size()-1)/2]<<endl;
        }
        else
        {
            cout<<(v[v.size()/2]+v[v.size()/2-1])/2<<endl;
        }
    }
}
            
