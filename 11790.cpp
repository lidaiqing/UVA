#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    int cnt =0;
    while(t--)
    {
        cnt++;
        int n;
        cin>>n;
        int height[n],weight[n];

        for(int i=0;i<n;i++)
            cin>>height[i];
        for(int i=0;i<n;i++)
            cin>>weight[i];

        int lis[n],lds[n];

        for(int i=0;i<n;i++)
        {
            lis[i] = 1;
            lds[i] = 1;
        }
        int lis_weight[n],lds_weight[n];
        for(int i=0;i<n;i++)
        {
            lis_weight[i] = weight[i];
            lds_weight[i] = weight[i];
        }
        for(int i=1;i<n;i++)
        {
            int mx_lis = 0,mx_lds = 0;
            for(int j=0;j<i;j++)
            {
                if(height[j] < height[i]){
                    if(lis_weight[j] + weight[i] > mx_lis){
                        mx_lis = lis_weight[j] + weight[i];
                        lis_weight[i] = mx_lis;
                    }
                
                }
                if(height[j] > height[i]){
                    if(lds_weight[j] + weight[i] > mx_lds){
                        mx_lds = lds_weight[j] + weight[i];
                        lds_weight[i] = mx_lds;
                    }
                }
            }
        }
        int lis_mx = 0, lis_w,lds_mx = 0,lds_w;

        for(int i=0;i<n;i++)
        {
           if(lis_weight[i]>lis_mx)
               lis_mx = lis_weight[i];
           if(lds_weight[i]>lds_mx)
               lds_mx = lds_weight[i];
        }
        cout<<"Case "<<cnt<<". ";
       /* for(int i=0;i<n;i++)
            cout<<lis[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<lds[i]<<" ";
        cout<<endl;*/
        if(lis_mx >= lds_mx){
            cout<<"Increasing ("<<lis_mx<<"). Decreasing ("<<lds_mx<<")."<<endl;
        }
        else{
            cout<<"Decreasing ("<<lds_mx<<"). Increasing ("<<lis_mx<<")."<<endl;
        }
    }
}
                        


