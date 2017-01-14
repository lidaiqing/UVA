#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    while (1) {
        int temp;
        cin>>temp;
        if (temp == 0) break;
        vector<int> v;
        v.push_back(temp);
        while (1) {
            cin>>temp;
            if (temp == 0) break;
            v.push_back(temp);
        }
        vector<int> diff;
        for (int i = 0; i < v.size()-1; i++)
            diff.push_back(abs(v[i] - v[i+1]));
        int ans = diff[0];
        for (int i = 1; i < diff.size(); i++)
            ans = gcd(ans,diff[i]);
        cout<<ans<<endl;
    }
}
