#include<bits/stdc++.h>
using namespace std;
int NStairs(int n,int k,int*dp){
	// Base case
	if(n==0)
    {
		dp[n]=1;
		return dp[n];
	}
     if(n<0)
     {
         return 0;
     }
	// Recursive case
	if(dp[n]!=-1)
    {
        return dp[n];
    }
	int ans = 0;
	for(int i=1;i<=k;i++)
    {
		ans += NStairs(n-i,k,dp);
	}
	dp[n]=ans;
	return dp[n];
}
int bottomup(int n,int k)
{
    int*dp1=new int [n+1];
    dp1[0]=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=0;
        for(int j=1;j<=k;j++)
        {
            if((i-j)>=0)
            {
                ans=ans+dp1[i-j];
            }
        }
        dp1[i]=ans;
    }
    return dp1[n];

}
int main()
{
  int dp[10000];
  for(int i=0;i<10000;i++)
  {
      dp[i]=-1;
  }
  int n,k=3;
  cin>>n;
  cout<<NStairs(n,k,dp)<<endl;
  cout<<bottomup(n,k)<<endl;
}
