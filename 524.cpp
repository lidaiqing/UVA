#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

bool is_prime[100];
vector<int> temp;
int n;
bool check(int ind,int num){
    for(int i=0;i<num;i++)
        if(temp[i]==ind)return false;
    return true;
}
void backtrack(int num)
{
    if(num==n){
        for(int i=0;i<n-1;i++)
            cout<<temp[i]<<" ";
        cout<<temp[n-1]<<endl;
        /*cout<<temp[0]<<" ";
        for(int i=n-1;i>1;i--)
            cout<<temp[i]<<" ";
        cout<<temp[1]<<endl;*/
    }
    else {
        
        for(int i=2;i<=n;i++)
        {
            if(check(i,num)){
                if(num!=n-1){
                    if(is_prime[temp[num-1]+i]){
                        temp.push_back(i);
                        backtrack(num+1);
                        temp.erase(temp.begin()+temp.size()-1);
                    }
                }
                else{
                    if(is_prime[temp[num-1]+i]&&is_prime[i+1]){
                        temp.push_back(i);
                        backtrack(num+1);
                        temp.erase(temp.begin()+temp.size()-1);
                    }
                }
            }
        }
    }
}
int main()
{
    
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=false,is_prime[1]=false;
    for(int i=2;i<100;i++)
    {
        if(is_prime[i]){
        for(int j=i+i;j<100;j+=i)
            is_prime[j]=false;
        }
    }
   // for(int i=0;i<100;i++)
        //if(is_prime[i])cout<<i<<endl;
    int cas=1;
    while(cin>>n)
    {
        if(cas!=1)cout<<endl;
        temp.clear();
        temp.push_back(1);
        cout<<"Case "<<cas++<<":"<<endl;
        backtrack(1);
        
    }
}

    
