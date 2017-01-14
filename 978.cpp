#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{

    int t;
    scanf("%d",&t);

    while(t--)
    {
        int B,SG,SB;

        scanf("%d%d%d",&B,&SG,&SB);
        
        priority_queue <int> green;
        priority_queue <int> blue;
        for(int i=0;i<SG;i++)
        {
            int temp;
            scanf("%d",&temp);
            green.push(temp);
        }
        for(int i=0;i<SB;i++)
        {
            int temp;
            scanf("%d",&temp);
            blue.push(temp);
        }
        while(green.size()&&blue.size())
        {
            vector<int> greenList,blueList;

            if(green.size()>=B&&blue.size()>=B)
            {
                for(int i=0;i<B;i++)
                {
                    int topGreen=green.top();
                    int topBlue=blue.top();
                    green.pop(),blue.pop();
                    if(topGreen>topBlue)
                    {
                        greenList.push_back(topGreen-topBlue);
                    }
                    else if(topGreen<topBlue)
                    {
                        blueList.push_back(topBlue-topGreen);
                    }
                }
            }
            else
            {
                int si=min(green.size(),blue.size());
                for(int i=0;i<si;i++)
                {   
                    int topGreen=green.top();//cout<<topGreen<<endl;
                    int topBlue=blue.top();
                    green.pop(),blue.pop();
                    //cout<<green.size()<<endl;
                    if(topGreen>topBlue)
                    {
                        greenList.push_back(topGreen-topBlue);
                    }
                    else if(topGreen<topBlue)
                    {
                        blueList.push_back(topBlue-topGreen);
                    }
                }
            }
            for(int i=0;i<greenList.size();i++)
                green.push(greenList[i]);
            for(int i=0;i<blueList.size();i++)
                blue.push(blueList[i]);
        }
        if(green.size()==0&&blue.size()==0)printf("green and blue died\n");
        else if(green.size()!=0)
        {
            printf("green wins\n");
            while(!green.empty())
            {
                printf("%d\n",green.top());
                green.pop();
            }
        }
        else
        {
            printf("blue wins\n");
            while(!blue.empty())
            {
                printf("%d\n",blue.top());
                blue.pop();
            }
        }
        if(t)printf("\n");
    }
}


        
