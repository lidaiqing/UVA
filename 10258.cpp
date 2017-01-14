#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct id{
    int solveNum;
    int p;
    int pp[50];
    bool check;
    bool state[15];
    int id;
};
bool comp( id l, id r)
{
    if(l.solveNum!=r.solveNum)return l.solveNum>r.solveNum;
    else{
        if(l.p!=r.p)
            return l.p<r.p;
        else
        {
            return l.id<r.id;
        }
    }


}

int main()
{

    int t;
    cin>>t;
    cin.ignore();
    string s;
    getline(cin,s);
    while(t--)
    {
        
        id team[105];
        for(int i=1;i<=100;i++)
        {
            team[i].solveNum=0;
            team[i].p=0;
            for(int j=1;j<=9;j++)
            {
                team[i].pp[j]=0;
                team[i].state[j]=false;
            }
            team[i].check=false;
            
            team[i].id=i;
        }

        
        //cout<<"test"<<endl;
        while(1)
        {
            string ss;
            getline(cin,ss);
            
            if(ss.empty()){
                    break;
            }

        istringstream iss(ss);
        int a,b,c;
        char d;
        iss>>a>>b>>c>>d;
       // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        //cout<<a<<" "<<b<<endl;
        team[a].check=true;

        if(d=='C')
        {
            if(!team[a].state[b]){

            team[a].state[b]=true;
            team[a].solveNum++;
            team[a].p+=c+team[a].pp[b];
            }
        }
        else if(d=='I')
        {   
            if(!team[a].state[b])
            team[a].pp[b]+=20;
        }

    }
        sort(team+1,team+101,comp);
        
        for(int i=1;i<=100;i++)
        {
            if(team[i].check)
            {
                cout<<team[i].id<<" "<<team[i].solveNum<<" "<<team[i].p<<endl;
            }
        }
        if(t)cout<<endl;

    }
}

        



