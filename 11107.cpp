#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100010
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int N;
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
int idx[MAX_N];
bool can(int mxLCP)
{
    bool check[105];
    memset(check,false,sizeof(check));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (LCP[i] == mxLCP) {
            if (!check[idx[SA[i]]]) {
                //cout<<SA[i]<<" "<<idx[SA[i]]<<endl;
                cnt++;
                check[idx[SA[i]]] = true;
            }
        }
    }
    if (cnt >= N / 2 + 1) return true;
    return false;
}
int main()
{

    while (1)
    {
        cin >> N;
        if (N == 0) break;
        string s;
        for (int i = 0; i < N; i++)
        {
            string temp;
            cin >> temp;
            char tm = 'z' + i + 1;
            temp += tm;
            for (int j = s.size(); j < s.size() + temp.size(); j++)
                    idx[j] = i;
            s += temp;
        }
        cout<<s<<endl;
        n = s.size();
        for (int i = 0; i < s.size(); i++)
            T[i] = s[i];
        
        constructSA();
        computeLCP();
        int mxLCP = -1;
        for (int i = 0; i < n; i++)
        {
            if (LCP[i] != 0 && can(LCP[i])) {
                cout<<i<<" "<<LCP[i]<<endl;
                mxLCP = max(mxLCP, LCP[i]);
            }
        }
        if (mxLCP == -1) cout<<"?"<<endl;
        else {
            int l = 0, r = mxLCP;
            while (l < r)
            {
                
                int mid = l + (r - l + 1) / 2;
                if (can(mid)) l = mid;
                else r = mid - 1;
            }
            if (l == 0) cout<<"?"<<endl;
            else cout<<l<<endl;
        }
    }
}

        
            
