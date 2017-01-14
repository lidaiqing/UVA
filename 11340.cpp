#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()
{

    int N;
    cin>>N;
    while(N--)
    {

        int K;
        cin>>K;
        int match[1000];
        memset(match,0,sizeof(match));

        for(int i=0;i<K;i++)
        {
            char a;int b;
            cin>>a>>b;

            match[(int)a+300]=b;
        }
        long long M;
        cin>>M;
        
        string s;
        double pay=0;
        cin.ignore();
        while(M--)
        {
            getline(cin,s);

            for(int i=0;i<s.size();i++)
            {
                pay+=match[(int)s[i]+300];
            }
        }
        pay/=100;
        printf("%.2f$\n",pay);
    }
}
