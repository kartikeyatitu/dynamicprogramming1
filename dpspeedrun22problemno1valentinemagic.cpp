#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll a[5000],b[5000],dp[5000][5000];
ll n,m;
ll solve(ll i,ll j)
{
    if(i==n)
    {
        //sare boys hogaye khatm so return
        return 0;
    }
    if(j==m)
    {
        //girls khatm hogayi to hame aisa kuch nai chahiye tha so
        return INT_MAX;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    ll op1=abs(a[i]-b[j])+solve(i+1,j+1);
    ll op2=solve(i,j+1);
    dp[i][j]=min(op1,op2);
    return dp[n-1][m-1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<m;j++)
    {
        cin>>b[j];
    }
    sort(a,a+n);
    sort(b,b+m);
    ll ans=solve(0,0);
    cout<<ans<<endl;

    return 0;
}


