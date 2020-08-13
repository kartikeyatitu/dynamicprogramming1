#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
//indian coin change problem through greedy approach which would be faster and does not fail in any testcase soo no need of dp based solution
int money;
int indicoin(int *coins,int n,int money)
{
    int ans=0;
    while(money>0)
    {

        int badaindex=upper_bound(coins,coins+n,money)-1-coins;
        cout<<coins[badaindex]<<"+";
        money-=coins[badaindex];
        ans++;
    }

    return ans;



}


int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>money;
        int coins[]={1,2,5,10,20,50,100,200,500,1000};
        int t=sizeof(coins)/sizeof(int);
        cout<<indicoin(coins,t,money)<<endl;
        return 0;
}
