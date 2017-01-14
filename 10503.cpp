#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int,int> >list;
int n,m;
vector<pair<int,int> >temp;
bool flag;
bool check[25];
void backtrack(int num)
{
    
    if(num==n+1){
        if(temp.back().second==list.back().first)
        {
            if(!flag){
                flag=true;
                      }
        }
    }
    else{
                    
        for(int i=1;i<list.size()-1&&!flag;i++)
        {
            if(!check[i]&&list[i].first==temp[num-1].second){
                check[i]=true;
                temp.push_back(list[i]);
                backtrack(num+1);
                temp.erase(temp.begin()+temp.size()-1);
                check[i]=false;
                
            }
            if(!check[i]&&list[i].second==temp[num-1].second){
                check[i]=true;
                temp.push_back(make_pair(list[i].second,list[i].first));
                backtrack(num+1);
                temp.erase(temp.begin()+temp.size()-1);
                check[i]=false;
            }
        }
        
    }

}

        
int main()
{

    while(1)
    {
        temp.clear();
        list.clear();

        memset(check,false,sizeof(check));
        cin>>n;
        if(n==0)break;
        
        cin>>m;
        int sta,stb,ena,enb;
        cin>>sta>>stb>>ena>>enb;
        temp.push_back(make_pair(sta,stb));
        list.push_back(make_pair(sta,stb));
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            list.push_back(make_pair(a,b));
        }
        list.push_back(make_pair(ena,enb));
        flag=false;
        backtrack(1);
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
