#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        int N;
        cin>>N;
        int s_m[N][N];
        int new_m[2*N][2*N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>s_m[i][j];
                new_m[i][j] = s_m[i][j];
            }
        }
        for(int i=0;i<N;i++)
            for(int j=N;j<2*N;j++)
                new_m[i][j] = s_m[i][j-N]; 
        for(int i=N;i<2*N;i++)
            for(int j=0;j<N;j++)
                new_m[i][j] = s_m[i-N][j];
        for(int i=N;i<2*N;i++)
            for(int j=N;j<2*N;j++)
                new_m[i][j] = s_m[i-N][j-N];
        for(int i=0;i<2*N;i++)
        {
            for(int j=0;j<2*N;j++)
            {
                if(i>0) new_m[i][j] += new_m[i-1][j];
                if(j>0) new_m[i][j] += new_m[i][j-1];
                if(i>0 && j>0) new_m[i][j] -= new_m[i-1][j-1];
            }
        }
        long long ans = -1000000000;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int ii=i;ii<2*N && abs(ii - i) < N;ii++){
                    for(int jj=j;jj<2*N && abs(jj - j) < N;jj++){
                        long long s = new_m[ii][jj];

                        if(i>0) s -= new_m[i-1][jj];
                        if(j>0) s -= new_m[ii][j-1];
                        if(i>0 && j>0) s += new_m[i-1][j-1];
                        ans = max(ans,s);
                        
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
        

