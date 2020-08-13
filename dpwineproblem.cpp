#include <iostream>
using namespace std;
int maxpro(int n,int*a,int dp[][100],int i,int j,int y)
{
    if(i>j)
    {
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int op1=a[i]*y+maxpro(n,a,dp,i+1,j,y+1);
    int op2=a[j]*y+maxpro(n,a,dp,i,j-1,y+1);
    int ans=max(op1,op2);
    dp[i][j]=ans;
    return ans;

}
int main()
{
    int dp[100][100];
    for(int i=0;i<100;i++)
    {
          for(int j=0;j<100;j++)
          {


        dp[i][j]=-1;
    }
    }
   int y;
   int a[]={2,3,5,1,4};
   int n=sizeof(a)/sizeof(int);
   cout<<maxpro(n,a,dp,0,n-1,1)<<endl;
  return 0;
}
