#include <bits/stdc++.h>

using namespace std;
const int MAX = 205;
int dp[MAX][MAX];
pair<int,pair<int,int> > parent[MAX][MAX];
int p[MAX][MAX];
int cnt;
string a, b;
void print()
{
   vector<int> op;
   int i = a.size(), j = b.size();
   while (1)
   {
       if (p[i][j] == -1) break;
       if (p[i][j] == 0) {
           op.push_back(0);
           i--;
           j--;
       }
       else if (p[i][j] == 3) {
           op.push_back(3);
           i--;
           j--;
       }
       else if (p[i][j] == 2) {
           op.push_back(2);
           i--;
       }
       else if (p[i][j] == 1) {
           op.push_back(1);
           j--;
       }
   }
   reverse(op.begin(), op.end());
   i = 1, j = 1;
   int v = 1;
   for (int k = 0; k < op.size(); k++)
   {
       if (op[k] == 0) {
           i++;
           j++;
           v++;
       }
       else if (op[k] == 1) {
           cout<<cnt<<" Insert "<<v<<","<<b[j-1]<<endl;
           v++;
           j++;
           cnt++;
       }
       else if (op[k] == 2) {
           cout<<cnt<<" Delete "<<v<<endl;
           cnt++;
       }
       else {
           cout<<cnt<<" Replace "<<v<<","<<b[j-1]<<endl;
           v++;
           j++;
           cnt++;
       }
   }
}
int main()
{
    bool first = true;
    while (getline(cin,a))
    {
        getline(cin,b);
        /*for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                parent[i][j] = make_pair(-1,make_pair(-1,-1));
        */
        if (first) {
            first = false;
        }
        else cout<<endl;
        memset(p,-1,sizeof(p));
        for (int i = 1; i < MAX; i++)
        {
            dp[0][i] = i;
            p[0][i] = 1;
            dp[i][0] = i;
            p[i][0] = 2;
        }
        dp[0][0] = 0;
        p[0][0] = -1;
        /*if (a.size() < b.size()) {
                for (int i = a.size(); i < b.size(); i++)
                    a += ".";
        }*/
        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= b.size(); j++)
            {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                    //parent[i][j] = make_pair(0,make_pair(i-1,j-1));
                    p[i][j] = 0;
                }
               /* else if (a[i-1] == '.') {
                        dp[i][j] = dp[i][j-1] + 1;
                        parent[i][j] = make_pair(1,make_pair(i,j-1));
                }*/
                else {
                    if (dp[i-1][j-1] <= dp[i-1][j] && dp[i-1][j-1] <= dp[i][j-1])
                    {
                        dp[i][j] = dp[i-1][j-1] + 1;
                        //parent[i][j] = make_pair(3,make_pair(i-1,j-1));
                        p[i][j] = 3;
                    }
                    else if (dp[i-1][j] <= dp[i-1][j-1] && dp[i-1][j] <= dp[i][j-1])
                    {
                        dp[i][j] = dp[i-1][j] + 1;
                        //parent[i][j] = make_pair(2,make_pair(i-1,j));
                        p[i][j] = 2;
                    }
                    else if (dp[i][j-1] <= dp[i-1][j-1] && dp[i][j-1] <= dp[i-1][j])
                    {
                        dp[i][j] = dp[i][j-1] + 1;
                        //parent[i][j] = make_pair(1,make_pair(i,j-1));
                        p[i][j] = 1;
                    }
                }
            }
        }
        cnt = 1;
        cout<<dp[a.size()][b.size()]<<endl;
        print();
    }
}
                    

        
