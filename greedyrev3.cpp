#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void solve(int n)
{
     int ans=0;
vector<int> v,v1;
     for(int i=0;i<n;i++);
     {
         string s;int b;
         cin>>s>>b;
         int j=i+1;
         v.push_back(j);
         v1.push_back(b);
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<v.size();i++)
    {
        ans+=abs((v[i])-(v1[i]));
    }
    cout<<ans<<endl;
}
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       int n;
       cin>>n;
       solve(n);

       return 0;
}
