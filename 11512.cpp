#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100010
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];

void countingSort(int k) {
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof(c));
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i+k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t; }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n ;i++)
        SA[i] = tempSA[i];
}

void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}
int Phi[MAX_N];
int LCP[MAX_N];
int PLCP[MAX_N];
void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i-1];
    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1) {PLCP[i] = 0; continue;}
        while (T[i + L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for (i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}
int count(string s1, string s2)
{
    int len1 = s1.size(), len2 = s2.size();
    int i = 0, j = 0;
    int ans = 0;
    while (i < len1) {
        j = 0;
        while (j < len2) {
            if (s1[i+j] == s2[j]) {
                if (j == len2 -1) ans++;
                j++;
            }
            else break;
        }
        i++;
    }
    return ans;

}
int main()
{
    int ca;
    cin >> ca;
    while (ca--)
    {
        string s;
        cin >> s;
        s += '$';
        for (int i = 0; i < s.size(); i++)
            T[i] = s[i];
        n = s.size();
        constructSA();
        computeLCP();
        int mxLCP = -1, ind = -1;
        string foundS = "Z";
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (LCP[i] != 0) {
                mxLCP = max(mxLCP, LCP[i]);
            }
        }
       // for (int i = 0; i < n; i++)
        //    cout<<i<<" "<<LCP[i]<<endl;
        for (int i = 0; i < n; i++)
        {
            if (LCP[i] == mxLCP) {
                if (s.substr(SA[i],mxLCP) < foundS)
                    foundS = s.substr(SA[i],mxLCP);
            }
        }
        if (mxLCP != -1) {
            cout<<foundS<<" "<<count(s, foundS)<<endl;
        }

        else cout<<"No repetitions found!"<<endl;
    }
}
