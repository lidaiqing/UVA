#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
using namespace std;
int drn[]={-2,-2,-1,1,2,2,1,-1};
int dcn[]={-1,1,2,2,1,-1,-2,-2};

int drk[]={-1,-1,-1,0,1,1,1,0};
int dck[]={-1,0,1,1,1,0,-1,-1};

int drq[]={1,2,3,4,5,6,7,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,-1,-2,-3,-4,-5,-6,-7};
int dcq[]={1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7};

int main()
{

    string s;
    while(cin>>s){
        for(int i=0;i<s.size();i++)
          if(s[i]!='P') s[i]= tolower(s[i]);
        
        
        bool mp[9][9];
        bool mmp[9][9];
        memset(mmp,true,sizeof(mmp));
        memset(mp,true,sizeof(mp));
        
        int row=1,l=0; 
        for(int i=0;i<s.size();i++)
        {
            int current=1,l=i;
            while(s[l]!='/'&&l<s.size())
            {
                if(s[l]>='1'&&s[l]<='8')
                    current+=s[l]-'0';
                else{
                    mmp[row][current]=false;
                    current++;
                }
                l++;
            }
            row++;
            i=l;
        }
        row=1,l=0;

        for(int i=0;i<s.size();i++)
        {
            int current=1,l=i;
            while(s[l]!='/'&&l<s.size())
            {   
                //cout<<s[l]<<endl;
                if(s[l]>='1'&&s[l]<='8')
                    current+=s[l]-'0';
                else{

                    if(s[l]=='n')
                    {
                       // cout<<row<<" "<<current<<" n"<<endl;
                        mp[row][current]=false;
                        int dr,dc;
                        for(int j=0;j<8;j++)
                        {
                            dr=row+drn[j];
                            dc=current+dcn[j];
                            if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                                mp[dr][dc]=false;
                        }
                    }
                    else if(s[l]=='k')
                    {
                       // cout<<row<<" "<<current<<" k"<<endl;
                        mp[row][current]=false;
                        int dr,dc;
                        for(int j=0;j<8;j++)
                        {
                            dr=row+drk[j];
                            dc=current+dck[j];
                            if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                                mp[dr][dc]=false;
                        }
                    }
                    else if(s[l]=='q')
                    {
                        mp[row][current]=false;
                        //cout<<row<<" "<<current<<" q"<<endl;
                        for(int j=current+1;j<=8;j++)
                        {
                            if(!mmp[row][j])break;
                            mp[row][j]=false;
                        }
                        for(int j=current-1;j>=1;j--)
                        {
                            if(!mmp[row][j])break;
                            mp[row][j]=false;
                        }
                        for(int j=row+1;j<=8;j++)
                        {
                            if(!mmp[j][current])break;
                            mp[j][current]=false;
                        }
                        for(int j=row-1;j>=1;j--)
                        {
                            if(!mmp[j][current])break;
                            mp[j][current]=false;
                        }
                            
                        for(int k=0;k<7;k++)
                         {
                                int dr,dc;
                                dr=row+drq[k];
                                dc=current+dcq[k];
                                if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                                {
                                    if(!mmp[dr][dc])break;
                                    mp[dr][dc]=false;
                                }
                         }
                              
                        for(int k=7;k<14;k++)
                         {
                                int dr,dc;
                                dr=row+drq[k];
                                dc=current+dcq[k];
                                if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                                {
                                    if(!mmp[dr][dc])break;
                                    mp[dr][dc]=false;
                                }
                         }
                              
                        for(int k=14;k<21;k++)
                         {
                                int dr,dc;
                                dr=row+drq[k];
                                dc=current+dcq[k];
                                if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                                {
                                    if(!mmp[dr][dc])break;
                                    mp[dr][dc]=false;
                                }
                         }
                              
                        for(int k=21;k<28;k++)
                         {
                                int dr,dc;
                                dr=row+drq[k];
                                dc=current+dcq[k];
                                if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                             {
                                    if(!mmp[dr][dc])break;
                                    mp[dr][dc]=false;
                                }
                         }



                        
                    }
                    else if(s[l]=='b')
                    {
                        mp[row][current]=false;
                        for(int k=0;k<7;k++)
                         {
                                int dr,dc;
                                dr=row+drq[k];
                                dc=current+dcq[k];
                                if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                                {
                                    if(!mmp[dr][dc])break;
                                    mp[dr][dc]=false;
                                }
                         }
                              
                        for(int k=7;k<14;k++)
                         {
                                int dr,dc;
                                dr=row+drq[k];
                                dc=current+dcq[k];
                                if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                                {
                                    if(!mmp[dr][dc])break;
                                    mp[dr][dc]=false;
                                }
                         }
                              
                        for(int k=14;k<21;k++)
                         {
                                int dr,dc;
                                dr=row+drq[k];
                                dc=current+dcq[k];
                                if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                                {
                                    if(!mmp[dr][dc])break;
                                    mp[dr][dc]=false;
                                }
                         }
                              
                        for(int k=21;k<28;k++)
                         {
                                int dr,dc;
                                dr=row+drq[k];
                                dc=current+dcq[k];
                                if(dr>=1&&dr<=8&&dc<=8&&dc>=1)
                             {
                                    if(!mmp[dr][dc])break;
                                    mp[dr][dc]=false;
                                }
                         }

                    }
                    else if(s[l]=='r')
                    {
                        mp[row][current]=false;

                      for(int j=current+1;j<=8;j++)
                        {
                            if(!mmp[row][j])break;
                            mp[row][j]=false;
                        }
                        for(int j=current-1;j>=1;j--)
                        {
                            if(!mmp[row][j])break;
                            mp[row][j]=false;
                        }
                        for(int j=row+1;j<=8;j++)
                        {
                            if(!mmp[j][current])break;
                            mp[j][current]=false;
                        }
                        for(int j=row-1;j>=1;j--)
                        {
                            if(!mmp[j][current])break;
                            mp[j][current]=false;
                        }
                    }
                    else if(s[l]=='p')
                    {
                        mp[row][current]=false;
                        if(row+1<=8&&current-1>=1)mp[row+1][current-1]=false;
                        if(row+1<=8&&current+1<=8)mp[row+1][current+1]=false;
                       // if(row-2>=1&&mmp[row-1][current])mp[row-2][current]=false;
                    }
                    else if(s[l]=='P')
                    {
                        mp[row][current]=false;
                        if(row-1>=1&&current-1>=1)mp[row-1][current-1]=false;
                        if(row-1>=1&&current+1<=8)mp[row-1][current+1]=false;
                    }
                    current++;
                
                }
                l++;
            }
                
                i=l;
                row++;
            
        }
       /* for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                cout<<mp[i][j];
            }
            cout<<endl;
        }*/

            int cnt=0;
            for(int i=1;i<=8;i++)
                for(int j=1;j<=8;j++)
                 if(mp[i][j])cnt++;

                
            cout<<cnt<<endl;
    }
        
    
}






                            

                        
