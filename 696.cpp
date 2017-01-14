#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    while(1){
        int n,m;
        cin>>n>>m;
        int ans;
        if(n==0&&m==0)break;
        else if(n==1)ans=m;
        else if(m==1)ans=n;
        else if(n==2)
                {
                    if((m%4)*2>=4)ans=(m/4)*4+4;
                    else ans=(m/4)*4+(m%4)*2;
                }
        else if(m==2) {
                    if((n%4)*2>=4)ans=(n/4)*4+4;
                    else ans=(n/4)*4+(n%4)*2;
                }

        
        else{
            
        ans=(m*n+1)/2;
        }
        printf("%d knights may be placed on a %d row %d column board.\n",ans,n,m);
        
    }
}
