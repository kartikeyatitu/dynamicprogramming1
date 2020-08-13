#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int n;
int a[1000000];
void solve(int n)
{
    int sum=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum%n!=0)
    {
        cout<<-1<<endl;
        return;
    }
    int diff=0;
    int max_load=0;
    sum=sum/n;
    for(int i=0;i<n;i++)
    {
        diff+=(a[i]-sum);
        int ans=max(diff,-diff);
        max_load=max(ans,max_load);
    }
    cout<<max_load<<endl;
    return;




}
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       int t;
       cin>>t;
       while(t--)
       {
           cin>>n;
           solve(n);
       }

       return 0;
}
