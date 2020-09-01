#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
//word break problem recursion+dp
string s;
vector<string> solve(string s,vector<string> &dic)
{
      unordered_map<string,vector<string>> dp;
      vector<string> res;
      if(dp.find(s)!=dp.end())
      {
         return dp[s];
      }
      for(auto words:dic)
      {
         if(s.substr(0,words.length())== words)   //this has the potential to be the first word
          {
             if(words.length()== s.length())
             {
                 res.push_back(words);
             }
              else
             {
                  vector<string> temp=solve(s.substr(word.length()),dic);
                  for(auto words1:temp)
                  {
                     res.push_back(words + " " + words1);
                  }
             }
         }
     }
     dp[s]=res;
     return res;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> dic("cats", "dog", "sand", "and", "cat");
        cin>>s;
        solve(s,dic,res);

       return 0;
}
