#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int main()
{

    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;

        multiset<int> myset;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                int temp;
                cin>>temp;
                myset.insert(temp);
            }

            multiset<int>::iterator low,high;

            low=myset.begin();
            high=myset.end();
            high--;
            ans+=*high-*low;
            myset.erase(low);
            myset.erase(high);
        }
        cout<<ans<<endl;
    }
}
