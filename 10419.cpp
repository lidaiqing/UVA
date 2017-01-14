#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAX 505
vector<int> primes;
bool isPrime[MAX];
struct state {
   // int num;
    vector<int> list;
    map<int,int> mp;
    int can;
};

string intTostring(int n)
{
    string s = "";
    while (n)
    {
        int digit = n % 10;
        n /= 10;
        s += digit + '0';
    }
    reverse (s.begin(), s.end());
    return s;
}
bool comp(state ls, state rs)
{
    string sl = "", sr = "";
    for (int i = 0; i < ls.list.size(); i++)
        sl += intTostring(ls.list[i]);
    for (int i = 0; i < rs.list.size(); i++)
        sr += intTostring(rs.list[i]);
    return sl < sr;
}
void sieve()
{
    for (int i = 0; i < MAX; i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < 1050; i++)
    {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < 1050; j = j + i)
                isPrime[j] = false;
        }
    }
    //sort(primes.begin(),primes.end(),comp);
}


state dp[1005][16];

state can(int n, int t)
{
    if (dp[n][t].can != -1) return dp[n][t];
    if (t == 1) {
        if (!isPrime[n]) {
            dp[n][t].can = 0;
            return dp[n][t];
        }
        else {
            dp[n][t].list.push_back(n);
            dp[n][t].mp[n]++;
            dp[n][t].can = 1;
            return dp[n][t];
        }
    }
    if (n == 1) {
        dp[n][t].can = 0;
        return dp[n][t];
    }
    vector<state> temp;
    for (int i = 0; i < primes.size(); i++)
    {
        if (t > 1 && primes[i] < n && can(n-primes[i], t-1).can) {
            if (primes[i] == 2 && dp[n-primes[i]][t-1].mp[2] == 0 ) {
                //cout << "asds" << endl;
                //mi = dp[n-primes[i]][t-1].list.back();
                dp[n][t] = dp[n-2][t-1];
                dp[n][t].list.push_back(2);
                dp[n][t].mp[2] = 1;
                temp.push_back(dp[n][t]);
                //return dp[n][t];
            }
            else if (primes[i] != 2 && dp[n-primes[i]][t-1].mp[primes[i]] <= 1) {
                //mi = dp[n-primes[i]][t-1].list.back();
                dp[n][t] = dp[n-primes[i]][t-1];
                dp[n][t].list.push_back(primes[i]);
                dp[n][t].mp[primes[i]]++;
                temp.push_back(dp[n][t]);
                //return dp[n][t];
            }
        }
    }
    
    if (temp.size() == 0) 
        dp[n][t].can = 0;
    else {
        sort(temp.begin(), temp.end(), comp);
        dp[n][t] = temp[0];
    }
    return dp[n][t];
}

int main()
{
    int case_num = 0;
    sieve();
    while (1)
    {
        case_num++;
        int N, t;
        cin >> N >> t;
        if (N == 0 && t == 0) break;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= t; j++) {
                dp[i][j].can = -1;
                dp[i][j].list.clear();
                dp[i][j].mp.clear();
            }
        }
        state ans = can(N,t);
        if (ans.can == 0) {
            cout << "CASE " << case_num << ":" << endl;
            cout << "No Solution." << endl;
        }
        else {
            sort(ans.list.begin(),ans.list.end());
            cout << "CASE " << case_num << ":" << endl;
            for (int i = 0; i < ans.list.size()-1; i++)
                cout <<ans.list[i] << "+";
            cout << ans.list.back() << endl;
        }
    }
}
