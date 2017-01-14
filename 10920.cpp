#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
struct node{
    int x,y;
    char face;
    int step;
};
int s,p;
bool visit[10000][10000];
void bfs(int stx,int sty,int key)
{
    node st;
    st.x=stx,st.y=sty+1,st.face='u',st.step=2;
    
    
    memset(visit,false,sizeof(visit));
    visit[stx][sty]=true;
    queue <node> q;
    q.push(st);
    while(!q.empty())
    {
        node top=q.front();
        q.pop();
        if(visit[top.x][top.y])continue;
        visit[top.x][top.y]=true;
        if(top.step==key)
        {
            cout<<"Line = "<<top.y<<", column = "<<top.x<<"."<<endl;
            return;
        }
        if(top.face=='u')
        {   
            if(!visit[top.x-1][top.y])
            {
                node temp;
                temp.x=top.x-1;
                temp.y=top.y;
                temp.face='l';
                temp.step=top.step+1;
                q.push(temp);
            }
            else 
            {
                node temp;
                temp.x=top.x;
                temp.y=top.y+1;
                temp.face=top.face;
                temp.step=top.step+1;
                q.push(temp);
            }
        }
        else if(top.face=='l')
        {   
            if(!visit[top.x][top.y-1])
            {
                node temp;
                temp.x=top.x;
                temp.y=top.y-1;
                temp.face='d';
                temp.step=top.step+1;
                q.push(temp);
            }
            else 
            {
                node temp;
                temp.x=top.x-1;
                temp.y=top.y;
                temp.face=top.face;
                temp.step=top.step+1;
                q.push(temp);
            }
        }
        else  if(top.face=='d')
        {   
            if(!visit[top.x+1][top.y])
            {
                node temp;
                temp.x=top.x+1;
                temp.y=top.y;
                temp.face='r';
                temp.step=top.step+1;
                q.push(temp);
            }
            else 
            {
                node temp;
                temp.x=top.x;
                temp.y=top.y-1;
                temp.face=top.face;
                temp.step=top.step+1;
                q.push(temp);
            }
        }
        else  if(top.face=='r')
        {   
            if(!visit[top.x][top.y+1])
            {
                node temp;
                temp.x=top.x;
                temp.y=top.y+1;
                temp.face='u';
                temp.step=top.step+1;
                q.push(temp);
            }
            else 
            {
                node temp;
                temp.x=top.x+1;
                temp.y=top.y;
                temp.face=top.face;
                temp.step=top.step+1;
                q.push(temp);
            }
        }
    }
}



            

int main()
{
    while(1)
    {
        cin>>s>>p;
        if(s==0&&p==0)break;

        int stx,sty;
        stx=(s+1)/2;
        sty=(s+1)/2;
        if(p==1)
        {
            cout<<"Line = "<<stx<<", column = "<<sty<<"."<<endl;
        }
        else
        {
            int idx;
            for(int i=3;;i+=2)
            {
                if(i*i>=p)
                {
                    idx=i;
                    break;
                }
            }
            int x,y;
            if(((idx*idx)-p)/(idx-1)==0)
            {
                x=stx+(idx-1)/2;
                y=sty+(idx-1)/2-(idx*idx-p);
            
            }
            else if(((idx*idx)-p)/(idx-1)==1)
            {
                y=sty-(idx-1)/2;
                x=stx+(idx-1)/2-(idx*idx-idx+1-p);
                
            }
            else if(((idx*idx)-p)/(idx-1)==2)
            {
                x=stx-(idx-1)/2;
                y=sty-(idx-1)/2+(idx*idx-2*idx+2-p);
                
            }
            else
            {
                y=sty+(idx-1)/2;
                x=stx-(idx-1)/2+(idx*idx-3*idx+3-p);
              
            }

            cout<<"Line = "<<y<<", column = "<<x<<"."<<endl;

            
    }
}



}
