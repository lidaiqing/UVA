#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    int cnt1 = 0;
    while(1)
    {
        int n,q;
        cin>>n>>q;
        if(n == 0 && q == 0) break;
        cnt1++;
        long long list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        cout<<"SET "<<cnt1<<":"<<endl;
        int cnt2 = 0;
        while(q--)
        {
            int d,m;
            cin>>d>>m;
            cnt2++;
            long long dp[n+1][m+1][21];
            memset(dp,0,sizeof(dp));

            
            for(int i=0;i<=n;i++)
                dp[i][0][0] = 1;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    for(int k=0;k<d;k++)
                    {
                        
                        int temp = (k - (list[i-1] % d))%d;
                        if(temp < 0)
                            temp += d;
                        
                        dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][temp];
                    }
                }
            }
            cout<<"QUERY "<<cnt2<<": "<<dp[n][m][0]<<endl;
        }
    }
}
            
            
