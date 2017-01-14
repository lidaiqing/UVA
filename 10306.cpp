#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{

    int n;
    cin>>n;

    while(n--)
    {
        int m,s;
        cin>>m>>s;

        int c_value[m+1], e_value[m+1];
        int dp[s+1][s+1];
        memset(dp,-1,sizeof(dp));

        for(int i=1;i<=m;i++)
        {
            cin>>c_value[i];
            cin>>e_value[i];
            dp[c_value[i]][e_value[i]] = 1;
        }

        
        for(int i=0;i<=s;i++)
        {
            for(int j=0;j<=s;j++)
            {

                for(int k=1;k<=m;k++)
                {
                    int mi = 1000000;
                    if( i - c_value[k] >= 0 && j - e_value[k] >= 0 )
                        if(dp[i-c_value[k]][j-e_value[k]] != -1)
                            mi = min(mi, dp[i-c_value[k]][j-e_value[k]]);
                    if(mi != 1000000) dp[i][j] = 1 + mi;
        
                }
            }
        }
        //cout<<dp[3][4]<<" "<<dp[4][3]<<" "<<dp[0][5]<<endl;
        int ans = 1000000;
        for(int i=0;i<=s;i++)
            for(int j=0;j<=s;j++)
                if( i*i + j*j == s*s && dp[i][j] != -1)
                    ans = min(ans, dp[i][j]);

        if(ans == 1000000) cout<<"not possible"<<endl;
        else cout<<ans<<endl;
    }
}

        

        


