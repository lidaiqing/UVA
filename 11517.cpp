#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        int p;
        cin>>p;
        int n;
        cin>>n;
        int dp[n+1][10005];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        int values[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>values[i];
            dp[i][values[i]] = 1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=10000;j++)
            {
                if(j - values[i] >= 0)
                {
                    if(dp[i-1][j] != -1 && dp[i-1][j-values[i]] == -1)
                        dp[i][j] = dp[i-1][j];
                    else if(dp[i-1][j] == -1 && dp[i-1][j-values[i]] != -1)
                        dp[i][j] = dp[i-1][j-values[i]] + 1;
                    else if(dp[i-1][j] != -1 && dp[i-1][j-values[i]] != -1)
                        dp[i][j] = min(dp[i-1][j], dp[i-1][j-values[i]] + 1);
                }
                else
                {
                    if(dp[i-1][j] != -1)
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        int price , ans;
        for(int i=p;i<=10000;i++)
        {
            if(dp[n][i] != -1)
            {
                price = i;
                ans = dp[n][i];
                break;
            }
        }


       
        
        cout<<price<<" "<<ans<<endl;
    }

        
                                  

        

           
}
                
