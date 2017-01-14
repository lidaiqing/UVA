#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
string table[]={"YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY","YNYYNYY","YNYYYYY","YYYNNNN",
                "YYYYYYY","YYYYNYY"};
string sequence[20];
bool flag;
int n;
void check(int cnt){
    
    if(cnt==n-2)return;
    else{
        bool flag1=true;
        for(int st=1;st<=n;st++){
        for(int i=0;i<7;i++)
        {
            if(sequence[st][i]=='Y'){
                for(int j=cnt-st+1;j<=cnt;j++)
                {
                    int ind=j-(cnt-st+1);
                    if(table[j][i]!=sequence[st-ind][i]){
                        flag1=false;
                    }
                   if(ind!=0){

                       for(int k=0;k<7;k++)
                         if(sequence[st-ind][k]=='Y'&&table[j][k]!='Y')
                            flag1=false;
                      }
                }
            }
          }
        }
        if(!flag1){
            check(cnt-1);
        }
        else flag=true;
        
    }

}
int main()
{
    int ca=1;
    while(1)
    {
        
        cin>>n;
        if(n==0)break;
        for(int i=1;i<=n;i++)
            cin>>sequence[i];
        
            flag=false;
            check(9);
            if(flag)cout<<"MATCH"<<endl;
            else cout<<"MISMATCH"<<endl;
       /* cout<<ca<<endl;ca++;
        for(int i=1;i<=n;i++)
            cout<<sequence[i]<<endl;*/
    }
}

