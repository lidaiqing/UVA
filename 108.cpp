#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

    int N;
    cin>>N;
    int m[N+1][N+1];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int g;
            cin>>g;
            if(i>0) g += m[i-1][j];
            if(j>0) g += m[i][j-1];
            if(i>0 && j>0) g -= m[i-1][j-1];
            m[i][j] = g;
        }
    }
    int ans = -100000;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int ii=i;ii<N;ii++){
                for(int jj=j;jj<N;jj++){

                    int s = m[ii][jj];
                    if(i>0) s -= m[i-1][jj];
                    if(j>0) s -= m[ii][j-1];
                    if(i>0 && j>0) s += m[i-1][j-1];
                    ans = max(ans,s);
                }
            }
        }
    }
    cout<<ans<<endl;
}

