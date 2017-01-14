#include <iostream>
#include <stdio.h>

using namespace std;
typedef long long ll;


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
                if(a>b)cout<<">"<<endl;
 		else if(a<b)cout<<"<"<<endl;
		else cout<<"="<<endl;
	}
}
