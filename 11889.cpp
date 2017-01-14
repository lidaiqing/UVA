#include <bits/stdc++.h>

using namespace std;

long long _sieve_size;
bitset<10000100> bs;
vector<long long> primes;
void sieve(long long upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; i++)
    {
        if (bs[i]) {
            for (long long j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}
vector<pair<int,int> > primeFactors(long long N)
{
    vector<pair<int,int> > factors;
    long long PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        if (N % PF == 0) {
            int cnt = 0;
            while (N % PF == 0) {
                cnt++;
                N /= PF;
            }
            factors.push_back(make_pair(PF,cnt));
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(make_pair(N,1));
    return factors;
}
long long find_LCM(long long a, long long c)
{
    vector<pair<int,int> > factor_a, factor_c;
    factor_a = primeFactors(a);
    factor_c = primeFactors(c);
    //cout<<"asd"<<endl;
    long long ans = 1;
    for (int i = 0; i < factor_a.size(); i++)
    {
        int pa = factor_a[i].first, na = factor_a[i].second;
        //cout<<pa<<" "<<na<<endl;
        bool flag = false;
        for (int j = 0; j < factor_c.size(); j++)
        {
            long long pc = factor_c[j].first, nc = factor_c[j].second;
            if (pa == pc) {
                flag = true;
                if (na != nc) ans *= pow(pc,nc);   
            }
           // cout<<ans<<endl;
        }
        if (!flag) return -1;
    }
    for (int i = 0; i < factor_c.size(); i++)
    {
        long long pc = factor_c[i].first, nc = factor_c[i].second;
        bool flag = false;
        for (int j = 0; j < factor_a.size(); j++)
        {
            long long pa = factor_a[j].first, na = factor_a[j].second;
            if (pa == pc) flag = true;
        }
        if (!flag) ans *= pow(pc,nc);
    }
            
    return ans;
}
    
int main ()
{
   sieve(1000000); 
   int T;
   cin>>T;
   while (T--)
   {
       long long a,c;
       cin>>a>>c;
       long long ans = find_LCM(a,c);
       if (ans == -1) cout<<"NO SOLUTION"<<endl;
       else cout<<ans<<endl;
   }
}

