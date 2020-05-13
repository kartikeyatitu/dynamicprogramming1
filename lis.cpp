#include<bits/stdc++.h>
using namespace std;
// llongest increasing subseeq that ends at i .iske iye hame pichle states ki janana boht zaroori hai bottom up lagayengay pichle state ki kiiti hai +this statte and maximum lengay sabka
//dp[i]=1+lis(previous states)
int lis(int* a,int n)
{
    int dp[100];
    for(int i=0;i<n;i++)
    {
        //base case
        dp[i]=1;
    }
    int best=-1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            // jth element can be absorbed by i th element
            if(a[j]<=a[i])

            {

                int clength=1+dp[j];
                dp[i]=max(clength,dp[i]);
            }
        }
        best=max(best,dp[i]);
    }

    return best;

}
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
     cout<<lis(a,n)<<endl;
    return 0;
}
