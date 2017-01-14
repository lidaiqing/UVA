#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

int num_add(int num1,int num2)
{
    int new_num = num1 + num2;
    int n_num = new_num;
    vector <int> digits;
    while (new_num){
        int digit = new_num % 10;
        digits.push_back(digit);
        new_num /= 10;
    }
    if (digits.size() > 4){
        for (int i = 3; i >= 0; i--)
        {
            new_num = new_num * 10 + digits[i];
        }
    }
    else
    {
        new_num = n_num;
    }
    return new_num;
}
int main()
{
    int cnt = 0;
    while (1) {
        cnt++;
        int L,U,R;
        cin>>L>>U>>R;
        if (L == 0 && U == 0 && R == 0) break;
        int RV[R];
        for (int i = 0; i < R; i++)
            cin>>RV[i];
        int dist[10000];
        memset(dist,-1,sizeof(dist));
        dist[L] = 0;
        queue <int> q;
        q.push(L);
        int ans = -1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == U){
                ans = dist[u];
                break;
            }
            for (int i = 0; i < R; i++)
            {
                int v = num_add(u,RV[i]);
                if (dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        //cout<<num_add(1023,1000)<<endl;
        cout<<"Case "<<cnt<<": ";
        if (ans == -1)cout<<"Permanently Locked"<<endl;
        else cout<<ans<<endl;
    }





}
