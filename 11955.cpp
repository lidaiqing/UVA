#include <bits/stdc++.h>

using namespace std;
void print(long long b,string name1,string name2,int k1,int k2)
{
    if (b != 1) cout<<b<<"*";
    if (k1 != 0) cout<<name1;
    if (k1 != 1 && k1 != 0) cout<<"^"<<k1;
    if (k2 != 0) cout<<"*"<<name2;
    if (k2 != 1 && k2 != 0) cout<<"^"<<k2;
    cout<<"+";
}
long long b[55][55];
int main()
{
    int T;
    cin>>T;
    b[0][0] = 1;
    for (int i = 1; i < 55; i++)
    {
        b[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            b[i][j] = b[i-1][j-1] + b[i-1][j];
        }
    }
    int ca = 0;
    while (T--)
    {
        ca++;
        string name1,name2,s;
        cin>>s;
        int pos;
        for (int i = 1; i < s.size(); i++)
            if (s[i] == '+') {
                pos = i;
                break;
            }
        name1 = s.substr(1,pos-1);
        //name2 = s.substr(pos+1,s.size()-4-pos);
        int k;
        if (s[s.size()-2] >= '1' && s[s.size()-2] <= '9') {
            k = (s[s.size()-2] - '0')*10 + s[s.size()-1] - '0';
            name2 = s.substr(pos+1,s.size()-5-pos);
        }
        else {
            k = s[s.size()-1] - '0';
            name2 = s.substr(pos+1,s.size()-4-pos);
        }
        cout<<"Case "<<ca<<": ";
        for (int i = 0; i < k; i++)
        {
            print(b[k][i],name1,name2,k-i,i);
        }
        cout<<name2;
        if (k != 1) cout<<"^"<<k<<endl;
        else cout<<endl;
        



    }
}

