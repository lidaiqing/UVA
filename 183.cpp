#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;
char mp[205][205];
int ans[205][205];
int n,m;
string s;
vector<char> anss;
bool check(int tr,int tc,int br,int bc)
{
    for(int i=tr;i<=br;i++)
        for(int j=tc;j<=bc;j++)
            if(mp[i][j]!=mp[tr][tc])return false;
    return true;
}
void divid(int tr,int tc, int br,int bc)
{

    if(br>n||bc>m)return;
    if(check(tr,tc,br,bc)){
        anss.push_back(mp[tr][tc]);
        return;
    }
    else{
        anss.push_back('D');
        int rr,cc;
        rr=round((br-tr)/2);
        cc=round((bc-tc)/2);
        if(tr!=br&&tc!=bc){
        divid(tr,tc,tr+rr,tc+cc);
        divid(tr,tc+cc+1,tr+rr,bc);
        divid(tr+rr+1,tc,br,tc+cc);
        divid(tr+rr+1,tc+cc+1,br,bc);
        }
        else if(tr==br)
        {
            divid(tr,tc,tr,tc+cc);
            divid(tr,tc+cc+1,tr,bc);
        }
        else if(tc==bc)
        {
            divid(tr,tc,tr+rr,tc);
            divid(tr+rr+1,tc,br,tc);
        }
    }
}
int pos;
void con(int tr,int tc,int br,int bc)
{  
    if(br>n||bc>m||tr<=0||tc<=0)return;
   // cout<<pos<<" "<<tr<<" "<<tc<<" "<<br<<" "<<bc<<endl;
    if(tr==br&&tc==bc)
    {
        if(s[pos]=='1')ans[tr][tc]=1;
        else if(s[pos]=='0')ans[tr][tc]=0;
        pos++;
        return;
    }
    
    if(s[pos]=='1'){
          for(int i=tr;i<=br;i++){
            for(int j=tc;j<=bc;j++){
                ans[i][j]=1;
            }
        }
          pos++;
          
        
    }
    else if(s[pos]=='0'){
        for(int i=tr;i<=br;i++){
            for(int j=tc;j<=bc;j++){
                ans[i][j]=0;
            }
        }
        pos++;
    }
    else {
        pos++;
        int rr,cc;
        rr=round((br-tr)/2);
        cc=round((bc-tc)/2);
        if(tr!=br&&tc!=bc){
        con(tr,tc,tr+rr,tc+cc);
        con(tr,tc+cc+1,tr+rr,bc);
        con(tr+rr+1,tc,br,tc+cc);
        con(tr+rr+1,tc+cc+1,br,bc);
        }
        else if(tr==br)
        {
            con(tr,tc,tr,tc+cc);
            con(tr,tc+cc+1,tr,bc);
        }
        else if(tc==bc)
        {
            con(tr,tc,tr+rr,tc);
            con(tr+rr+1,tc,br,tc);
        }
    }
}


int main()
{

    while(1)
    {
        char T;
        cin>>T;
        if(T=='#')break;
        anss.clear();
        cin>>n>>m;
        
        if(T=='B'){

                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                        cin>>mp[i][j];
                
                printf("D%4d%4d\n",n,m);
                divid(1,1,n,m);
                for(int i=0;i<anss.size();i++)
                {
                    cout<<anss[i];
                    if((i+1)%50==0)cout<<endl;
                }
                if(anss.size()%50!=0)cout<<endl;
        }
        else{
            pos=0;
            cin>>s;
            con(1,1,n,m);
            printf("B%4d%4d\n",n,m);
            vector<int > ansss;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    ansss.push_back(ans[i][j]);
            for(int i=0;i<ansss.size();i++)
            {
                cout<<ansss[i];
                if((i+1)%50==0)cout<<endl;
            }
            if(ansss.size()%50!=0)cout<<endl;
        }
    }
}


                

    
        
