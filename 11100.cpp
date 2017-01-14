#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int l,int r)
{
    return l>r;
}
int main()
{



    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        cout<<endl;
        vector<int> list;

        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            list.push_back(temp);
        }
        vector<int> newList;
        
        sort(list.begin(),list.end(),comp);
        for(int i=0;i<n;i++)
            newList.push_back(list[i]);
        vector< vector<int> > v;

        while(list.size())
        {
            vector<int> temp;
            temp.push_back(list[0]);
            list.erase(list.begin());
            for(int i=0;i<list.size();i++)
            {
                if(list[i]<temp.back())
                {
                    temp.push_back(list[i]);
                    list.erase(list.begin()+i);
                    i--;
                }
            }
            v.push_back(temp);
        }
        
        cout<<v.size()<<endl;
        bool first=true;
        for(int i=0;i<v.size();i++)
        {
            first=true;
            for(int j=i;j<newList.size();j+=v.size())
            {
                if(first)first=false;
                else cout<<" ";
                cout<<newList[j];
                          
            }
            cout<<endl;
        
        }
    }
}

