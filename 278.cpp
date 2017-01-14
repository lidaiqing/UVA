#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

        int t;
        cin>>t;
        while(t--){

            char ind;
            cin>>ind;
            int n,m;
            cin>>n>>m;
            if(ind=='r'||ind=='Q')
                cout<<min(m,n)<<endl;
            else if(ind=='K'){
                if(n%2==0&&m%2==0)
                    cout<<m/2*n/2<<endl;
                else if(n%2==0&&m%2!=0)
                    cout<<(n/2)*(m+1)/2<<endl;
                else if(m%2==0&&n%2!=0)
                    cout<<(m/2)*(n+1)/2<<endl;
                else cout<<(m+1)/2+(n+1)/2<<endl;
        
            else{
                if(n%2==0&&m%2==0)
                    cout<<n/2*m<<endl;
                else if(n%2!=0&&m%2==0)
                    cout<<(m/2)*n<<endl;
                else if(n%2==0&&m%2!=0)
                    cout<<(n/2)*m<<endl;
                else{
                    cout<<(m/2+1)*(n/2+1)+(m/2)*(n/2)<<endl;
                }
            }
        }
}
