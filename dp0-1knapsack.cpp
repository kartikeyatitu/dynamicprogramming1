#include<bits/stdc++.h>
using namespace std;
int knapsack(int*wt,int*prices,int dp[][100],int n,int w)
{
    if(n==0 || w==0)
    {
        dp[n][w]=0;
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];


    }

    int inc=0,exc=0;
    //including last
    if(wt[n-1]<=w)
    {
    inc=prices[n-1]+knapsack(wt,prices,dp,n-1,w-wt[n-1]);
    }
    //excluding
    exc=0+knapsack(wt,prices,dp,n-1,w);
    dp[n][w]=max(inc,exc);
    return dp[n][w];
}
int bottomup(int*wt,int*prices,int n,int w )
{
    int dp[n+1][w+1]={0};
    for(int i=0;i<=n;i++)
    {
        for(int w1=0;w1<=w;w1++)
        {
            if(i==0 || w1==0)
            {
                dp[i][w1]=0;
            }
            else
            {
                int inc,exc;
                inc=exc=0;
                if(wt[i-1]<=w1)
                {
                inc=prices[i-1]+dp[i-1][w1-wt[i-1]];
                }
              exc=0+dp[i-1][w1];
              dp[i][w1]=max(inc,exc);
            }
    }
}
for(int i=0;i<=n;i++){
		for(int w1=0;w1<=w;w1++){
			cout<<dp[i][w1]<<" ";
		}
		cout<<endl;
	}

	return dp[n][w];

}


int main()
{
    int wt[]={2,2,3,1};
    int prices[]={5,20,20,10};
    int n=4;
    int w=5;
    int dp[100][100];
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(wt,prices,dp,n,w)<<endl;
    cout<<bottomup(wt,prices,n,w)<<endl;
    return 0;
}
