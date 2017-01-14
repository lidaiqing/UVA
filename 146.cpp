#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{

    while(1)
    {
        string s;
        cin>>s;
        if(s=="#")break;
        if(next_permutation(s.begin(),s.end()))
            cout<<s<<endl;
        else cout<<"No Successor"<<endl;
    }
}
