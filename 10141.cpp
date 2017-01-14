#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;
struct id{
	string name;
	double d;
	int r;
};
string s;
int main(){
	int c=0;
	cin.ignore();
	while(1){
	c++;
	int n,p;
	scanf("%d%d",&n,&p);
	if(n==0&&p==0)break;
	
	
	for(int i=1;i<=n;i++)
	{
		getline(cin,s);
		cin.clear();
	}
	id a[p+1];
	int mxr=0;
	double mid=1000000;
	string ms;
	for(int i=1;i<=p;i++){
		cin>>a[i].name;
		cin.ignore();
		scanf("%lf",&a[i].d);
		scanf("%d",&a[i].r);
		for(int j=1;j<=a[i].r;j++)
			{
				getline(cin,s);
				cin.clear();
			}
		if(a[i].r>mxr){
			mxr=a[i].r;
			ms=a[i].name;
			mid=a[i].d;
		}
		else if(a[i].r==mxr){
			if(a[i].d<mid){
				mxr=a[i].r;
				ms=a[i].name;
				mid=a[i].d;
			}
		}
	}
	cout<<"RFP #"<<c<<endl;
	cout<<ms<<endl;
      	cout<<endl;
	}
}
	
