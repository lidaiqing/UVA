#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        bool check[30];
        memset(check,false,sizeof(check));
        int numE=0;
        while(1)
        {
            string s;
            cin>>s;
            if(s[0]=='*')break;
            check[s[1]-'A']=true;
            check[s[3]-'A']=true;
            numE++;
        }
        string s;
        int numV=0,numA=0;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<='Z'&&s[i]>='A'){
                numV++;
                if(!check[s[i]-'A'])numA++;
            }
        }
        
        printf("There are %d tree(s) and %d acorn(s).\n",numV-numE-numA,numA);
    }
}
