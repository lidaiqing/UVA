#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{

    while(1)
    {

        int n,m;
        cin>>n>>m;
        if(n==0&&m==0)break;

        priority_queue <long long> pq1,pq2;

        for(int i=0;i<n;i++)
        {
            long long temp;
            cin>>temp;
            pq1.push(temp);
        }
        for(int i=0;i<m;i++)
        {
            long long temp;
            cin>>temp;
            pq2.push(temp);
        }
        long long cnt=0;
        while(pq1.size()&&pq2.size())
        {

            long long top1=pq1.top();
            long long top2=pq2.top();
            if(top1>top2)pq1.pop();
            else if(top1<top2)pq2.pop();
            else {
                pq1.pop();
                pq2.pop();
                cnt++;
            }
        }

        cout<<cnt<<endl;
    }
}

