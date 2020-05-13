#include<bits/stdc++.h>
using namespace std;
/*longest common subsequence
note recursively approach karengay ise
1. n e m a t o d e
2. e m p t y
length of lcs 3 'emt'
highly used in biogenetics
suppose a biologist discovers a new dna sequence and wants to match to which animals this dna sequence is most matching or common so this algo can be used
jiski lcs sabse zada that shares the mximum genes with the newly discovered dna
 yj\xi a g g t a b
 g
 x
 t
 x
 a
 y
 b

 case 1:if x vale me a ki jagah g hota to in other sense if(x[i]==y[j]): ans=1+lcs(x[i+1],y[j+1])
 case 2: agar same nai hai to  possible hai ki x vala poora y ke sath lcs bana le an vice versa is also true
         1.1{{lcs(x[i],y[j+1])
         1.2{{lcs(x[i+1],y[j])
  max(1.1,1.2) bcoz we want maximum
*/
int lcs(int dp[][100],string s,string s1,int n,int m)
{


  if(n==0 || m==0)
  {

      dp[n][m]=0;
      return dp[n][m];
  }
  if(dp[n-1][m-1]!=-1)
  {
      return dp[n-1][m-1];

  }
  if (s[n-1] == s1[m-1])
{


        dp[n-1][m-1]= 1 + lcs(dp,s,s1, n-1, m-1);
        return dp[n-1][m-1];
}

    else
    {


         dp[n-1][m-1]=max(lcs(dp,s,s1, n, m-1), lcs(dp,s,s1, n-1, m));



    return dp[n-1][m-1];
    }
}
int bottomuplcs(string s,string s1,int n,int m)
{
    int dp[100][100];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s[i-1]==s1[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];

            }
            else
            {

             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }
        }
    }
    return dp[n][m];



}


int main()
{
    int dp[100][100];
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {

            dp[i][j]=-1;
        }
    }
   string s,s1;
   cin>>s>>s1;
   int n,m;
   n=s.length();
   m=s1.length();
   cout<<lcs(dp,s,s1,n,m)<<endl;
   cout<<bottomuplcs(s, s1, n, m)<<endl;
   return 0;








}
