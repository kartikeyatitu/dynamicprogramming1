 #include <bits/stdc++.h>
using namespace std;
int minstepstopd(int n,int*dp)
{
    if(n==1)
    {
        dp[n]=0;
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;

    op1=minstepstopd(n-1,dp)+1;
    if(n%3==0)
    {
        op2=minstepstopd(n/3,dp)+1;

    }
    if(n%2==0)
    {
        op3=minstepstopd(n/2,dp)+1;
    }
    dp[n]= min(op1,min(op2,op3));
    return dp[n];
}
int bottomup(int n)
{
  int *dp = new int[n+1];
  dp[1]=0;

  for(int i=2;i<=n;i++)
  { int op1,op2,op3;
   op1=op2=op3=INT_MAX;
  op1=dp[i-1]+1;
  if(i%2==0)
  {
      op2=dp[i/2]+1;
  }
  if(i%3==0)
  {
      op3=dp[i/3]+1;
  }
  dp[i]= min(op1,min(op2,op3));
  }
    return dp[n];




}
int main()
{
    int n;
    cin>>n;
    int dp[100];
    for(int i=0;i<100;i++)
    {


        dp[i]=-1;
    }
    cout<<minstepstopd(n,dp)<<endl;
    cout<<bottomup(n)<<endl;
}


