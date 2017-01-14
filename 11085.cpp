#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;
vector< vector<int> > v;
vector<int> temp;
bool check(int r,int c)
{
    
    for(int i=0;i<c;i++)
    {
           if(temp[i]==r||abs(c-i)==abs(r-temp[i]))
               return false;   
    }
    return true;
}
void backtrack(int num)
{

    if(num==8){
    
            v.push_back(temp);
            return;
    }
    else{
        for(int i=0;i<8;i++)
        {
            if(check(i,num)){
            temp.push_back(i);
            backtrack(num+1);
            temp.erase(temp.begin()+temp.size()-1);
            }
        }
    }
}
        
int main()
{

    int col[8];
    backtrack(0);
    int cas=1;
    while(cin>>col[0])
    {
        for(int i=1;i<8;i++)
            cin>>col[i];
        for(int i=0;i<8;i++)
            col[i]--;
        int mi=100000;

        for(int i=0;i<v.size();i++)
        {
            int cnt=0;
            for(int j=0;j<8;j++)
            {
                if(col[j]!=v[i][j])cnt++;
            }
            if(cnt<mi){
                mi=cnt;
            }
        }
        cout<<"Case "<<cas++<<": ";
        cout<<mi<<endl;
    }
}
        
        

        
