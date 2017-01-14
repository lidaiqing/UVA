#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int a,b,col[8];
int cnt=0;

bool check(int rr,int cc)
{
    for(int i=0;i<cc;i++)
        if(col[i]==rr||abs(cc-i)==abs(rr-col[i]))
            return false;
    return true;
}
void back(int c)
{

    if(c==8&&col[b]==a){
        cnt++;
        printf("%2d      ",cnt);
        for(int i=0;i<7;i++)
            printf("%d ",col[i]+1);
        printf("%d",col[7]+1);
        printf("\n");
    }
    else{
    
        for(int i=0;i<8;i++)
        {
            if(check(i,c)){
                col[c]=i;
                back(c+1);
            }
        }
    }
}
            
int main()
{


    int t;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d %d",&a,&b);
        a--,b--;
        cnt=0;
        memset(col,0,sizeof(col));
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n");
        printf("\n");

        back(0);

        if(t)printf("\n");
    }
}
