#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{

    while(1)
    {
        int n;
        cin>>n;
        if(n == 0)break;

        long long a[n],ans = 0,sum = 0;
        for(int i = 0;i <n;i++)
        {
            cin>>a[i];
            sum += a[i];
            ans = max(ans,sum);
            if(sum < 0) sum = 0;
        }

        if(ans > 0) cout<<"The maximum winning streak is "<<ans<<"."<<endl;

        else cout<<"Losing streak."<<endl;
    }
}
        
           

        
