#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
	int t;
	cin>>t;
        int c=0;
	while(t--){
	c++;
	int n;
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		mx=max(mx,temp);
	}
	cout<<"Case "<<c<<": "<<mx<<endl;
	}
}
