#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	while(1){
	double h,u,d,f;
	cin>>h>>u>>d>>f;
	f/=100;
	if(h==0)break;
	double hh=0,uu=u;
        int dd=1;
	while(1){
	if(dd!=1){
	  if(uu-u*f>=0)uu-=u*f;
	  else uu=0;
	  }
	  hh+=uu;//cout<<hh<<endl;
          if(hh>h){
		cout<<"success on day "<<dd<<endl;
		break;
		}

	  hh-=d;
	
	   if(hh<0){
		cout<<"failure on day "<<dd<<endl;
		break;
		}
	   dd++;
	}
    }
}
