#include <bits/stdc++.h>

using namespace std;

long long _sieve_size;
bitset<10000010> bs;
vector<int> primes;
bool is_prime[1000005];
void sieve(long long upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; i++)
    {
        if (bs[i]) {
                for (long long j = i * i; j <= _sieve_size; j += i)
                     bs[j] = 0;
        primes.push_back((int)i);
        }
    }
}

bool isPrime(long long N)
{
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int main()
{
    long long U,L;
    sieve(70000);
    while (cin>>L)
    {
        cin>>U;
        long long  mi = 100000000, mx = -1;
        long long  mi1,mi2, mx1,mx2;
        for (int i = 0; i <= U - L; i++)
            is_prime[i] = true;
        if (L == 1) is_prime[0] = false;
        for (int i = 0; i < primes.size(); i++) {
            long long start = (long long) ceil((double)L/primes[i]);
            if (start == 1) start++;
            for (long long j = start; j * primes[i] - L <= U - L; j++) {
                is_prime[j*primes[i]-L] = false;
                     // cout<<j*primes[i]<<endl;
            }
        }
        
        long long a = -1, b = -1;
        for (long long i = 0; i <= U - L; i++)
        {
            if (is_prime[i]) {
                    a = i;
                    if (b != -1) {
                        //cout<<b<<" "<<a<<endl;
                        int dist = a - b;
                        if (dist > mx) {
                            mx = dist;
                            mx1 = b + L;
                            mx2 = a + L;
                            }
                        if (dist < mi) {
                            mi = dist;
                            mi1 = b + L;
                            mi2 = a + L;
                            }
                    }
                        
                        b = a;
            }
        }
        if (mx != -1) {
            cout<<mi1<<","<<mi2<<" are closest, "<<mx1<<","<<mx2<<" are most distant."<<endl;
        }
        else cout<<"There are no adjacent primes."<<endl;
    }
}

                    

