#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int cnt = 0;
    while (1)
    {
        cnt++;
        int a,b;
        cin>>a>>b;
        if (a == 0 && b == 0) break;
        int dist[105][105];
        for (int i = 0; i < 105; i++){
            for (int j = 0; j < 105; j++){
                if (i == j ) dist[i][j] = 0;
                else dist[i][j] = 1000000;
            }
        }
        while (1)
        {
            a--,b--;
            dist[a][b] = 1;
            cin>>a>>b;
            if (a == 0 && b == 0) break;
        }
        for (int k = 0; k < 105; k++){
            for (int i = 0; i < 105; i++){
                for (int j = 0; j < 105; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        double num_path = 0, total_len = 0;
        for (int i = 0; i < 105; i++){
            for (int j = 0; j < 105; j++){
                if (dist[i][j] != 1000000 && i != j){
                    num_path++;
                    total_len += dist[i][j];
                }
                
            }
        }//cout<<num_path<<" "<<total_len<<endl;
        double ans = (total_len / num_path);
        printf("Case %d: average length between pages = %.3f clicks\n",cnt,ans);
    }
}
        
            
            
