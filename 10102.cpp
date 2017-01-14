#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{

    int m;
    while(cin>>m)
    {
        
        char board[m+1][m+1];

        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                cin>>board[i][j];
        int mx=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int mi=10000000;
                if(board[i][j]=='1')
                {
                    for(int ii=1;ii<=m;ii++)
                    {
                        for(int jj=1;jj<=m;jj++)
                        {
                            if(board[ii][jj]=='3')
                            {
                                //cout<<"asdas"<<endl;
                                mi=min(mi,abs(ii-i)+abs(jj-j));
                            }
                        }
                    }
                }
                if(mi!=10000000)mx=max(mx,mi);
            }
        }

        cout<<mx<<endl;
    }
}
