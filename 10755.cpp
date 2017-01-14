#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;

        long long m[21][21][21];
        for(int i=0;i<A;i++){
            for(int j=0;j<B;j++){
                for(int k=0;k<C;k++){
                    long long g;
                    cin>>g;
                    if(i>0) g += m[i-1][j][k];
                    if(j>0) g += m[i][j-1][k];
                    if(k>0) g += m[i][j][k-1];
                    if(i>0 && j>0) g -= m[i-1][j-1][k];
                    if(i>0 && k>0) g -= m[i-1][j][k-1];
                    if(j>0 && k>0) g -= m[i][j-1][k-1];
                    if(i>0 && j>0 && k>0) g += m[i-1][j-1][k-1];
                    m[i][j][k] = g;
                }
            }
        }
        long long mx = INT_MIN;
        for(int i=0;i<A;i++){
            for(int j=0;j<B;j++){
                for(int k=0;k<C;k++){
                    for(int ii=i;ii<A;ii++){
                        for(int jj=j;jj<B;jj++){
                            for(int kk=k;kk<C;kk++){
                                long long g = m[ii][jj][kk];
                                if(i>0) g -= m[i-1][jj][kk];
                                if(j>0) g -= m[ii][j-1][kk];
                                if(k>0) g -= m[ii][jj][k-1];
                                if(i>0 && j>0) g += m[i-1][j-1][kk];
                                if(i>0 && k>0) g += m[i-1][jj][k-1];
                                if(j>0 && k>0) g += m[ii][j-1][k-1];
                                if(i>0 && j>0 && k>0) g -= m[i-1][j-1][k-1];

                                mx = max(mx,g);
                            }
                        }
                    }
                }
            }
        }
        cout<<mx<<endl;
        if(t) cout<<endl;
    }
}
