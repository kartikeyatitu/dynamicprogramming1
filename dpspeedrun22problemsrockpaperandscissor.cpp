#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000003
//diwali puzzle
double dp[105][105][105];
void set_dp()
{
    for(int i=0;i< 102;i++)
    {
        for(int j=0;j<102;i+j++)
        {
            for(int k=0;k<102;k++)
            {

                dp[i][j][k]=-1.0;
            }
        }
    }
}
double f1(int r,int s,int p)  // survival of rock
{
    if(r==0 or s==0)
    {
        return 0.0;
    }
    if(p==0)
    {
        return 1.0;
    }
    if(dp[r][s][p]!=-1.0)
    {
        return dp[r][s][p];
    }

    double total=r*s+s*p+r*p;
    double ret=0.0;
    ret+=f1(r-1,s,p)*((r*p)/total);   // rock and paper
    ret+=f1(r,s-1,p)*((r*s)/total);
    ret+=f1(r,s,p-1)*((s*p)/total);
    dp[r][s][p]=ret;
    return ret;
}
double f2(int r,int s,int p) //survival of scissor
{
    if(p==0 or s==0)
    {
        return 0.0;
    }
    if(r==0)
    {
        return 1.0;
    }
    if(dp[r][s][p]!=-1.0)
    {
        return dp[r][s][p];
    }

    double total=r*s+s*p+r*p;
    double ret=0.0;
    ret+=f2(r-1,s,p)*((r*p)/total);   // rock and paper
    ret+=f2(r,s-1,p)*((r*s)/total);
    ret+=f2(r,s,p-1)*((s*p)/total);
    dp[r][s][p]=ret;
    return ret;
}
double f3(int r,int s,int p)//survial of paper
{
  if(r==0 or p==0)
    {
        return 0.0;
    }
    if(s==0)
    {
        return 1.0;
    }
    if(dp[r][s][p]!=-1.0)
    {
        return dp[r][s][p];
    }

    double total=r*s+s*p+r*p;
    double ret=0.0;
    ret+=f3(r-1,s,p)*((r*p)/total);   // rock and paper
    ret+=f3(r,s-1,p)*((r*s)/total);
    ret+=f3(r,s,p-1)*((s*p)/total);
    dp[r][s][p]=ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        int r,s,p;
         cin>>r>>s>>p;
       //  memset(dp,-1.0,sizeof(dp));
          set_dp();
          double ans1=f1(r,s,p);

         //memset(dp,-1.0,sizeof(dp));
          set_dp();
          double ans2=f2(r,s,p);
         //memset(dp,-1.0,sizeof(dp));
          set_dp();
          double ans3=f3(r,s,p);
         cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }


    return 0;
}


