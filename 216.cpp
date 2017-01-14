#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

double dist[15][15];
int x[15], y[15];
int n;
int parent[15];
double memory[15][(1<<10)];
double tsp(int pos,int mask)
{
    if(mask == (1<<n)-1)
        return 0;
    if(memory[pos][mask] != -1)
        return memory[pos][mask];
    double mi = 1000000.0;
    int pi;
    for(int nxt=0;nxt<=n-1;nxt++)
    {
        if((nxt != pos) && !(mask & (1<<nxt)))
        {
            double mi = min(mi,dist[pos][nxt] + tsp(nxt, mask | (1<<nxt)) + 16); 
        }
    }
    
    return memory[pos][mask] = mi;
}
void back_print(int pos)
{
    if (pos == -1) return;

    back_print(parent[pos]);
    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2f feet.\n",x[pos],y[pos],x[parent[pos]],y[parent[pos]],dist[pos][parent[pos]]+16);
}


    
int main()
{
    int cnt = 0;
    while(1)
    {

        
        cin>>n;
        if(n == 0) break;
        cnt++;
        printf("**********************************************************\n");
        printf("Network #%d",cnt);

        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }

        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j){
                    dist[i][j] = sqrt(abs((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<(1<<n);j++)
            {
                memory[i][j] = -1;
             }
         }
        double ans = tsp(0,1);
        parent[0] = -1;
        int last;
        
       /* for(int i=0;i<n;i++)
        {
            if (parent[i])
        }*/
        //cout<<last<<endl;
        back_print(last);
        printf("Number of feet of cable required is %0.2f.\n",ans);
    }
}

        

        

        
        
        


        

        

        
