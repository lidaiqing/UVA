#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        int population[25];
        memset(population,0,sizeof(population));
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            population[a*5+b]=c;
        }
        int ans[5];
        int distance=10000000;
        bool flag=false;
        for(int a=0;a<25&&!flag;a++){
            for(int b=0;b<25&&!flag;b++){
                for(int c=0;c<25&&!flag;c++){
                    for(int d=0;d<25&&!flag;d++){
                        for(int e=0;e<25&&!flag;e++){
                            if(b!=a&&c!=a&&c!=b&&d!=a&&d!=b&&d!=c&&e!=a&&e!=b&&e!=c&&e!=d){
                            int mi=0,dis=1000000;
                            for(int i=0;i<25;i++){
                                    if(population[i]!=0)
                                    {
                                        dis=100000;
                                        dis=min(dis,population[i]*(abs(a/5-i/5)+abs(a%5-i%5)));
                                        dis=min(dis,population[i]*(abs(b/5-i/5)+abs(b%5-i%5)));
                                        dis=min(dis,population[i]*(abs(c/5-i/5)+abs(c%5-i%5)));
                                        dis=min(dis,population[i]*(abs(d/5-i/5)+abs(d%5-i%5)));
                                        dis=min(dis,population[i]*(abs(e/5-i/5)+abs(e%5-i%5)));
                                        mi+=dis;
                                    }
                                
                            }
                            if(mi<distance)
                            {
                                distance=mi;
                                ans[0]=a,ans[1]=b,ans[2]=c,ans[3]=d,ans[4]=e;
                            }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<4;i++)
            cout<<ans[i]<<" ";
        cout<<ans[4]<<endl;
    }
}
                            
