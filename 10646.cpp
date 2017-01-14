#include <iostream>
#include <stdio.h>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main(){

	int t;
	int ct=0;
	cin>>t;
	while(t--)
	{
		ct++;
		vector<pair<char,char> >vv;
		vector<pair<char,char> >v;
		
		for(int i=27;i>=1;i--)
		{
			string s;
			cin>>s;
			vv.insert(vv.begin(),make_pair(s[0],s[1]));
			
			
		}
		for(int i=25;i>=1;i--)
		{
			string s;
			cin>>s;
			v.insert(v.begin(),make_pair(s[0],s[1]));
			
		}
                
		int Y=0;
		for(int i=1;i<=3;i++)
		{
			int X;
                        if(vv[0].first>='2'&&vv[0].first<='9')X=vv[0].first-'0';
			else X=10;
			Y+=X;
			vv.erase(vv.begin(),vv.begin()+11-X);
		}

		vv.insert(vv.begin(),v.begin(),v.end());

		cout<<"Case "<<ct<<": "<<vv[vv.size()-Y].first<<vv[vv.size()-Y].second<<endl;
	}
}

