#include <bits/stdc++.h>
using namespace std;
int maxsum(int*a,int n)
{
    int dp[100]={0};
    dp[0]=a[0]>0?a[0]:0;
    int max_sofar=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        max_sofar=max(dp[i],max_sofar);
    }
    return max_sofar;


}
int main()
{
    int a[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int n=sizeof(a)/sizeof(int);
    cout<<maxsum(a,n)<<endl;


}
