#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
vector <char> letter;
vector <char> w[256];
int size;
map <char, bool> visit;
bool valid;
bool check(char e)
{
    for (int i = 0; i < w[e].size(); i++)
        if (visit[w[e][i]])
            return false;
    return true;
}
void dfs(vector <char> temp, int cur)
{
    
    if (cur == size )
    {   
        valid = true;
        for (int i = 0; i < temp.size()-1; i++)
            cout<<temp[i]<<" ";
        cout<<temp[size-1]<<endl;
        return;
    }
    for (int i = 0; i < letter.size(); i++)
    {
        if (!visit[letter[i]] && check(letter[i])){//cout<<letter[i]<<endl;
            temp.push_back(letter[i]);
            visit[letter[i]] = true;
            dfs(temp,cur+1);
            temp.pop_back();
            visit[letter[i]] = false;
        }
    }
}
    
        
int main()
{
    int T;
    cin>>T;
    string blank;
    cin.ignore();
    while(T--)
    {
        getline(cin,blank);
        string s;
        getline(cin,s);
        //cout<<s<<endl;
        for (int i = 0; i < 256; i++)
        {
            w[i].clear();
        }
        letter.clear();
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= 'A' && s[i] <= 'Z') {
                letter.push_back(s[i]);;
            }
        sort(letter.begin(), letter.end());

       // memset(in,false,sizeof(in));
        size = letter.size();
        string input;
        getline(cin,input);
        istringstream ss(input);
        
        char a,b,c;
        while(ss >> a >> b >> c)
        {
            //cout<<con[0]<<" "<<con[1]<<" "<<con[2]<<endl;
            w[a].push_back(c);
        }
        valid = false;   
        //memset(visit, false, sizeof(visit));
        vector <char> temp;
        dfs(temp,0);
        if (!valid) cout<<"NO"<<endl;
        if (T > 0) cout<<endl;
        
    }
}


            
        
