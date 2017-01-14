#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int color[105];
vector <int> ans;
int mx;
vector <int> con[105];
int n,m;
bool visit[105];
void backtrack(int num)
{
    if(num==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(color[i])cnt++;
        if(cnt>mx){
            mx=cnt;
            ans.clear();
            for(int i=1;i<=n;i++)
                if(color[i])ans.push_back(i);
        }
    }
    else{
        
            
            
        bool flag=false;
        for(int j=0;j<con[num].size()&&!flag;j++)
            if(color[con[num][j]]){
                flag=true;}
        if(!flag){
            color[num]=1;
            backtrack(num+1);
            color[num]=0;
            backtrack(num+1);
        }
        else {
            color[num]=0;
            backtrack(num+1);
        }
        
    

    }
}
        
int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        ans.clear();
        for(int i=0;i<105;i++)
            con[i].clear();

        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            con[a].push_back(b);
            con[b].push_back(a);
        }
        memset(color,0,sizeof(color));
        memset(visit,false,sizeof(visit));
        mx=0;
        backtrack(1);
        cout<<mx<<endl;
        for(int i=0;i<ans.size()-1;i++)
            cout<<ans[i]<<" ";
        cout<<ans.back()<<endl;
    }
}

        
