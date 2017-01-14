#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector <int> list;
vector <int> dp;
int table[1000000];
int parent[1000000];

void print(int pos)
{
    if(pos == -1)return;
    print(parent[pos]);
    cout<<list[pos]<<endl;
}
int main()
{

     int temp;

     while(cin>>temp)
     {
         list.push_back(temp);
     }
     
     int size = list.size();
     for(int i=0;i<size;i++)
         parent[i] = -1;
     dp.push_back(list[0]);
     table[0] = 0;
     for(int i=1;i<size;i++)
     {
         vector<int>::iterator up;
         up = lower_bound(dp.begin(),dp.end(),list[i]);
         if(up == dp.begin() + dp.size()){ 
             dp.push_back(list[i]);
             table[dp.size()-1] = i;
             parent[i] = table[dp.size()-2];
         }
         else
         { 
             int ind = up - dp.begin();
             if(ind>0) parent[i] = table[ind - 1];
             table[ind] = i;
             dp[ind] = list[i];
             
         }
     }
    // for(int i=0;i<dp.size();i++)
         //cout<<dp[i]<<" "<<table[i]<<endl;
     // for(int i=0;i<size;i++)
     //    cout<<parent[i]<<" ";
   //  cout<<endl;


    


     int longest = dp.size(), pos = table[dp.size()-1];
     cout<<longest<<endl;
     cout<<"-"<<endl;
     print(pos);
     
}


     


