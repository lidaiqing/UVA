#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int cnt=0;
    while(1)
    {
        cnt++;
        int b,s;
        cin>>b>>s;
        if(b==0&&s==0)break;

        vector<int> boy,girl;
        for(int i=0;i<b;i++)
        {
            int temp;
            cin>>temp;
            boy.push_back(temp);
        }
        for(int i=0;i<s;i++)
        {
            int temp;
            cin>>temp;
            girl.push_back(temp);
        }
        sort(boy.begin(),boy.end());
        if(b<=s)cout<<"Case "<<cnt<<": 0"<<endl;
        else
        {
            cout<<"Case "<<cnt<<": "<<b-s<<" "<<boy[0]<<endl;
        }
    }
}
