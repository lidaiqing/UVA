#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main()
{
    int N;
    cin>>N;
    cin.ignore();
    while (N--) {
        vector<int> v;
        string s;
        getline(cin,s);
        istringstream ss(s);
        int temp;
        while (ss>>temp) {
            v.push_back(temp);
        }
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                ans = max(ans,gcd(v[i],v[j]));
            }
        }
        cout<<ans<<endl;
    }
}
