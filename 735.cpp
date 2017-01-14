#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    set <int> region;
    for(int i=0;i<=20;i++)
    {
        region.insert(i);
        region.insert(i*2);
        region.insert(i*3);
        region.insert(50);
    }
    vector<int> list;
    for(set<int>::iterator it=region.begin();it!=region.end();it++)
                list.push_back(*it);
    while(1)
    {
        int num;
        scanf("%d",&num);

        if(num<=0){
            printf("END OF OUTPUT\n");
            break;}
               int cntc=0,cntp=0;

        set<vector<int> > check;
        for(int i=0;i<list.size();i++){
            for(int j=0;j<list.size();j++){
                for(int k=0;k<list.size();k++){
                        if(list[i]+list[j]+list[k]==num)
                        {   
                          cntp++;
                          vector<int> v;
                          v.push_back(list[i]);
                          v.push_back(list[j]);
                          v.push_back(list[k]);
                          sort(v.begin(),v.end());
                          if(check.count(v)==0){
                              cntc++;
                              check.insert(v);
                          }
                        }
                }
            }
        }

        if(cntp==0)printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",num);
        else{
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",num,cntc);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",num,cntp);
        }
       printf("**********************************************************************\n");

    }
}
