#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long fac[25];
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= 20; i++)
        fac[i] = fac[i-1] * i;
    int T;
    cin>>T;
    int cnt = 0;
    while (T--)
    {
        cnt++;
        string s;
        cin>>s;
        int char_cnt[27];
        memset(char_cnt,0,sizeof(char_cnt));
        for (int i = 0 ; i < s.size(); i++)
            char_cnt[s[i]-'A']++;
        long long ans = fac[s.size()];
        for (int i = 0; i < 26; i++)
            if (char_cnt[i] >= 2) ans /= fac[char_cnt[i]];
        cout<<"Data set "<<cnt<<": "<<ans<<endl;
    }
}

