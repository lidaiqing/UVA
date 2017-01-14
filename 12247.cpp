#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool comp(int l,int r)
{
	return l<r;
}
int main(){

	while(1){
	int a[3],b[2];

	for(int i=0;i<3;i++)
	cin>>a[i];
	cin>>b[0]>>b[1];
	if(a[0]==0)break;
	bool visit[53];
	memset(visit,false,sizeof(visit));
        for(int i=0;i<3;i++)
		visit[a[i]]=true;
	visit[b[0]]=true;
	visit[b[1]]=true;
	sort(a,a+3,comp);
	sort(b,b+2,comp);
	int now[3];
	bool flag=false;
	for(int i=1;i<=52;i++)
	{
	    if(visit[i])continue;
	    now[0]=b[0];
	    now[1]=b[1];
	    now[2]=i;
	    sort(now,now+3,comp);
            if((now[0]>a[1])||(now[1]>a[2])){
			cout<<i<<endl;
			flag=true;
			break;}
	    
	}
	if(!flag)cout<<"-1"<<endl;
	    
		
     }
}
	
