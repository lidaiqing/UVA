#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <utility>

using namespace std;

int main()
{

    int cnt = 0;
    while(1)
    {

        int n;
        cin>>n;
        if(n == 0) break;
        double dist[25][25];
        int x[25], y[25];
        cnt++;
        printf("**********************************************************\n");
        printf("Network #%d\n",cnt);
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j){
                    dist[i][j] = 16 + sqrt(abs((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
                }
            }
        }
        int ans_perm[n], list_perm[n];
        for(int i = 0; i < n; i++)
            list_perm[i] = i;
        double ans = 10000000;
        do{
            double temp = 0;
            for(int i = 0; i < n - 1; i++)
                temp += dist[list_perm[i]][list_perm[i+1]];
            if (temp < ans){
                ans = temp;
                for(int j = 0; j < n; j++)
                    ans_perm[j] = list_perm[j];
            }
        }while (next_permutation(list_perm, list_perm + n));
        for(int i = 0; i < n-1; i++)
        {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",x[ans_perm[i]], y[ans_perm[i]], x[ans_perm[i+1]], y[ans_perm[i+1]], dist[ans_perm[i]][ans_perm[i+1]]);
        }
        printf("Number of feet of cable required is %.2f.\n", ans);
    }
}
        


