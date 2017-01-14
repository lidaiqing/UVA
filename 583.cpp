#include <bits/stdc++.h>

using namespace std;

const long long MAX = 50000;
bool is_prime[MAX];
vector<int> primes;
void sieve()
{
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false, is_prime[1] = false;
    for (long long i = 2; i < MAX; i++)
    {
        if (is_prime[i]) {
            for (long long j = i * i; j < MAX; j += i)
                is_prime[j] = false;
            primes.push_back(i);
        }
    }
}

vector<int> primeFactors(long long N)
{
    vector<int> factors;
    long long PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        if (N % PF == 0) {
            while (N % PF == 0)
            {
                N /= PF;
                factors.push_back(PF);
            }
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(N);
    return factors;
}

int main()
{
    sieve();
    long long N;
    while (1)
    {
        cin>>N;
        if (N == 0) break;
        if (N < 0) {
            vector<int> ans = primeFactors(-N);
            cout<<N<<" = -1";
            for (int i = 0; i < ans.size(); i++)
                cout<<" x "<<ans[i];
            cout<<endl;
        }
        else if (N > 0) {
            vector<int> ans = primeFactors(N);
            cout<<N<<" = "<<ans[0];
            for (int i = 1; i < ans.size(); i++)
                cout<<" x "<<ans[i];
            cout<<endl;
        }
    }
}
