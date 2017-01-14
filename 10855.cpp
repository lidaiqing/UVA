#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

char s[1000][1000];
char ss[1000][1000];
int N,n;

void rotate()
{
    char temp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[j][i]=ss[n-i-1][j];
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ss[i][j]=temp[i][j];
}

int main()
{
    while(1)
    {
                cin>>N>>n;
        if(N==0&&n==0)
            break;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            cin>>s[i][j];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>ss[i][j];
    

        int cnt[4];
        memset(cnt,0,sizeof(cnt));
        for(int t=0;t<4;t++)
        {
            if(t!=0)rotate();
               
            for(int i=0;i<=N-n;i++)
            {
                for(int j=0;j<=N-n;j++)
                {
                    bool flag=false;
                    for(int k=0;k<n&&!flag;k++)
                    {
                        for(int l=0;l<n&&!flag;l++)
                        {
                            if(s[i+k][j+l]!=ss[k][l])
                                flag=true;
                        }
                    }
                    if(!flag)cnt[t]++;
                }
            }
        }
        for(int i=0;i<3;i++)
            cout<<cnt[i]<<" ";
        cout<<cnt[3]<<endl;
    }
}
        
        

        
        


