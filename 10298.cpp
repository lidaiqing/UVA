#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while (1)
    {
        cin >> s;
        if (s == ".") break;
        int ans = 1;
        for (int i = 2; i <= s.size(); i++)
        {
            if (s.size() % i == 0)
            {
                int L = s.size() / i;
                bool flag = true;
                for (int j = L; j < s.size(); j++)
                {
                    if (s[j] != s[j%L]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) ans = max(ans,i);
            }
        }
        cout<<ans<<endl;
    }
}
