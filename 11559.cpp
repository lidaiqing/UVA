#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;

int main()
{
        int N,H,W;

	while(scanf("%d",&N)!=EOF)
	{   //cout<<"asds"<<endl;
		long long B;

        cin>>B>>H>>W;
        
	
	int price[H+1];
	int pos[H+1][W+1];
 	
	for(int i=1;i<=H;i++)
	{
		cin>>price[i];
		for(int j=1;j<=W;j++)
		{
			cin>>pos[i][j];
		}
	}
	
	bool flag=false;
	int mi=100000;
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(pos[i][j]>=N&&N*price[i]<=B)
			{
			flag=true;
			mi=min(mi,price[i]);
			}
		}
	}
	
	if(flag)cout<<N*mi<<endl;
	else cout<<"stay home"<<endl;
	}
}
