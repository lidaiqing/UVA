#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
int m[4][4];
struct node{
    int r,c;
};
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

bool bfs()
{

    int mm[4][4];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            mm[i][j]=m[i][j];
    bool visit[4][4];
    memset(visit,false,sizeof(visit));

    queue <node> q;
    node st;
    st.r=1,st.c=1;
    q.push(st);
    while(!q.empty())
    {
        node top=q.front();
        q.pop();
        if(visit[top.r][top.c])continue;
        visit[top.r][top.c]=true;
        int sum=0;
        for(int i=0;i<4;i++)
        {
            node temp;
            temp.r=top.r+dr[i];
            temp.c=top.c+dc[i];
            if(temp.r>=1&&temp.r<=3&&temp.c>=1&&temp.c<=3)
            {
                sum+=mm[temp.r][temp.c];
            }
            q.push(temp);
        }
        //cout<<sum<<endl;
        m[top.r][top.c]=sum%2;
    }
    bool flag=true;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(m[i][j]!=mm[i][j])
                flag=false;
    return flag;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin.ignore();
        getline(cin,s);
        char cm[4][4];

        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>cm[i][j];
                m[i][j]=cm[i][j]-'0';
            }
        }

        
        for(int i=1; ;i++)
        {
            bool flag=bfs();
           // for(int k=1;k<=3;k++)
               // for(int j=1;j<=3;j++)
                  //  cout<<m[k][j]<<endl;
            if(flag){
                if(i-2<0)cout<<"-1"<<endl;
                else cout<<i-2<<endl;
                break;
            }
        }
    }
}
