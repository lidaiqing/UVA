#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{

    int m,mm,n;
    while(cin>>m)
    {
        cin>>n;

        int p[n+1],f[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>p[i]>>f[i];
        }


        int dp[n+1][m+201];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=200+m;j++)
                dp[i][j] = -100000000;
        dp[0][0] = 0;
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m+200;j++)
            {
                
                dp[i][j] = dp[i-1][j];
                if(p[i] <= j)dp[i][j] = max(dp[i][j],dp[i-1][j-p[i]] + f[i]);

            }
        }
        for(int i=0;i<=200+m;i++)
        {
            if((i<=m)||(i>2000 && i<=200 + m))
            ans = max(ans,dp[n][i]);
        }
    
        cout<<ans<<endl;
    }
}
                        

        
