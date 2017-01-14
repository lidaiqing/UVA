#include <bits/stdc++.h>

using namespace std;
vector<int> primes;
const int MAX = 1000005;
bool is_prime[MAX];
int main()
{
    for (int i = 0; i < MAX; i++)
        is_prime[i] = true;
    is_prime[0] = 0, is_prime[1] = 0;
    for (long long i = 2; i < MAX; i++)
    {
        if (is_prime[i]) {
            for (long long j = i*i; j < MAX; j += i)
                is_prime[j] = false;
            primes.push_back(i);
        }
    }
    while (1) {
        int n;
        cin>>n;
        if (n == 0) break;
        int ans1, ans2;
        for (int i = 0; i < primes.size(); i++)
        {
            ans1 = primes[i];
            if (is_prime[n-ans1]) {
                ans2 = n - ans1;
                break;
            }
        }
        cout<<n<<" = "<<ans1<<" + "<<ans2<<endl;
    }
}
                    
    

