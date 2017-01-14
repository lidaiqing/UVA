#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int n;
const long long  MAXIND=3*100000;
const long long MAXN=100005;
int a[MAXN];
int frequence[MAXN];
int ind[MAXN];
int M[MAXIND];
int query(int node,int b,int e,int i,int j)
{ 
    int ret;

    if(b>e||b>j||e<i)return -1;
    if(b>=i&&e<=j)
        return M[node];
    else{

        int mid=(b+e)/2;
        int left,right;
        left=query(node*2,b,mid,i,j);
        right=query(node*2+1,mid+1,e,i,j);
        if(left==-1)ret=right;
        if(right==-1)ret=left;
        if(left>=right)ret=left;
        else ret=right;
        return ret;
    }
    
    
}

     
void initialize(int node,int b,int e)
{

    if(b==e)
        M[node]=frequence[b];
    else{

        initialize(2*node,b,(b+e)/2);
        initialize(2*node+1,(b+e)/2+1,e);

        if(M[2*node]>M[2*node+1])M[node]=M[2*node];
        else M[node]=M[2*node+1];
         }
}

int main()
{

    int q;
    while(1)
    {
        cin>>n;
        if(n==0)break;

        cin>>q;

        int st=0,current=-1000000;
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]!=current&&i!=n-1)
            {
                current=a[i];
                
                for(int j=st;j<i;j++)
                {
                    ind[j]=st;
                    frequence[j]=i-st;
                }
                st=i;
            }
            if(i==n-1)
            {
                for(int j=st;j<=i;j++)
                {
                    ind[j]=st;
                    frequence[j]=i-st+1;
                }
            }
        }
      //  for(int i=0;i<n;i++)
         //   cout<<ind[i]<<endl;
        
        initialize(1,0,n-1);
        for(int i=0;i<q;i++)
        {
            int left,right;
            cin>>left>>right;
            left--;
            right--;
            int cnt1,cnt2,ans;
            if(a[left]==a[right])ans=right-left+1;
            else
            {
                cnt1=frequence[left]-(left-ind[left]);
                cnt2=right-ind[right]+1;
                ans=max(cnt1,cnt2);

                int temp=query(1,0,n-1,left+cnt1,ind[right]-1);
                ans=max(ans,temp);

            }
            cout<<ans<<endl;

        }
    }
}
        

        
