#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[210][10005][25];
int main()
{

    while(1)
    {
        int n,x,t,k;
        cin>>n>>x>>t>>k;
        if(n==0 && x==0 && k==0 && t==0)break;

        int p[2*k+5];
        int v[2*k+5];
        for(int i=1;i<=k;i++)
        {
            cin>>p[i];
            double sum = 0;
            for(int j=0;j<=n;j++)
            {
                double temp;
                cin>>temp;
                sum +=temp;
            }
            v[i] = sum;
        }
        for(int i=k+1;i<=2*k;i++)
        {
            p[i] = p[i-k];
            v[i] = v[i-k];
        }
        int total = x*(n+1); 
        //memset(dp,0,sizeof(dp));
        for(int i=0;i<=2*k;i++)
            for(int j=0;j<=total;j++)
                for(int l=0;l<=2*(n+1);l++)
                    dp[i][j][l] = 0;
        
                
        int ans = 0;
        for(int i=1;i<=2*k;i++)
        {
            for(int j=0;j<=total;j++)
            {
                for(int l=0;l<=2*(n+1);l++)
                {
                    dp[i][j][l] = dp[i-1][j][l];
                   // int consume = ceil((t*(n+1) + p[i])*0.1) + p[i];
                    if(p[i] <= j && l > 0)
                        dp[i][j][l] = max(dp[i][j][l],dp[i-1][j-p[i]][l-1] + v[i]);

                  //  ans = max(ans,dp[i][j][l]);
                }
            }
        }
        for(int i=1;i<=2*k;i++)
            for(int j=0;j<=total;j++)
                for(int l=0;l<=2*(n+1);l++)
                {
                    double temp;
                    temp = (ceil((j + t*(n+1)) * 0.1) + j*1.0)/ (n+1) + t;
                    if(temp <= x) ans = max(ans,dp[i][j][l]);
                }
        double rec = double(ans) / (n+1);
        printf("%.2f\n",rec);
    }
}
        
        
