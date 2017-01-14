#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <string.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        int board[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>board[i][j];

        vector<int >v;
        for(int i=0;i<n;i++)
        {
            v.push_back(i);
        }
        bool check[n];
        int mi=100000;
        do{
            memset(check,false,sizeof(check));
            int sum=0;
            int minimum=100000,ind;
            for(int i=0;i<v.size();i++)
            {
                minimum=100000;
                for(int j=0;j<n;j++)
                {
                    if(!check[j]){
                        if(board[j][v[i]]<minimum){
                            minimum=board[j][v[i]];
                            ind=j;
                        }
                    }
                }
                check[ind]=true;
                sum+=board[ind][v[i]];
                    
            }
                
            if(sum<mi)mi=sum;
        }while(next_permutation(v.begin(),v.end()));
        
        cout<<mi<<endl;
    }
}
           
