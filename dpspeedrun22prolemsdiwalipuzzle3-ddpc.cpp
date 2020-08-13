#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000003
//diwali puzzle
ll dp[105][3][105];
ll n,k;
ll solve(ll i,ll prv,ll c)
{
    if(i==n)
    {
        if(c==k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[i][prv][c]!=-1)
    {
        return dp[i][prv][c];
    }
    ll ans=0;
    if(prv==1)
    {
        ans+=solve(i+1,1,c+1);
    }
    else
    {
        ans+=solve(i+1,1,c);
    }
    ans%=MOD;
    ans+=solve(i+1,0,c);
    ans%=MOD;
    dp[i][prv][c]=ans;
    return ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        cout<<(solve(1,1,0)+solve(1,0,0))%MOD<<endl;
    }


    return 0;
}


