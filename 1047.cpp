#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct common{
    vector <int> tower;
    long long population;
};
long long tower[25];
common csa[15];
int mx=0,ans[25];
int n,actualUse,m;
vector<int> tempAns;
bool check[25];
void backtrack()
{
    
    for(int i=0;i<(1<<n);i++){
        int cnt=0;
        for(int j=0;j<n;j++)
            if(i&(1<<j))cnt++;
        if(cnt!=actualUse)continue;
        for(int j=0;j<n;j++)
            if(i&(1<<j))tempAns.push_back(j);
        sort(tempAns.begin(),tempAns.end());
        int sum=0;
        for(int i=0;i<tempAns.size();i++)
            sum+=tower[tempAns[i]];
        //cout<<sum<<endl;
        for(int i=0;i<m;i++)
        {
            int count=0;
            for(int j=0;j<csa[i].tower.size();j++)
            {
                for(int k=0;k<tempAns.size();k++)
                {
                    if(tempAns[k]==csa[i].tower[j])
                        count++;
                }
            }
            count--;
            if(count>-0)sum-=csa[i].population*count;
       
        }
       /* for(int i=0;i<tempAns.size();i++)
            cout<<tempAns[i]+1<<" ";
        cout<<sum<<endl;
*/
        if(sum>mx)
        {
            mx=sum;
            for(int i=0;i<actualUse;i++)
                ans[i]=tempAns[i];
        }
        tempAns.clear();
    }
        return;
}

int main()
{

    int caseNum=0;
    
    while(1)
    {
        caseNum++;
        cin>>n>>actualUse;
        if(n==0&&actualUse==0)break;
        memset(check,false,sizeof(check));
        mx=0;
        for(int i=0;i<15;i++)
            csa[i].tower.clear();
        for(int i=0;i<n;i++)
            cin>>tower[i];

        cin>>m;
    
        for(int i=0;i<m;i++)
        {
            int tt;
            cin>>tt;
            for(int j=0;j<tt;j++)
            {
                int temp;
                cin>>temp;
                temp--;
                csa[i].tower.push_back(temp);
            }
            int pop;
            cin>>pop;
            csa[i].population=pop;
        }
        backtrack(); 
        printf("Case Number  %d\n",caseNum);
        printf("Number of Customers: %d\n",mx);
        printf("Locations recommended: ");
        for(int i=0;i<actualUse-1;i++)

            cout<<ans[i]+1<<" ";
        cout<<ans[actualUse-1]+1<<endl;
        printf("\n");

    }
}
        


