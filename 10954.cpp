#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{


    while(1)
    {

        int n;
        cin>>n;
        if(n==0)break;

        priority_queue<int,vector<int>, greater<int> > pq;

        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            pq.push(temp);
        }
        int cost=0;
        while(!pq.empty())
        {

            int top1,top2;
            top1=pq.top();
            pq.pop();
            top2=pq.top();
            pq.pop();
            cost+=top1+top2;//cout<<cost<<endl;
            if(pq.empty())break;
            pq.push(top1+top2);
        }
        cout<<cost<<endl;
    }
}
