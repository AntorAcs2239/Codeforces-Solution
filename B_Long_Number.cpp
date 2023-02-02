#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define endl '\n'
#define ld long double
#define mod 1000000007        
#define gcd __gcd
vector<int>graph[200005];
vector<int>visited(200005,0);
vector<int>paren(200005,0);
void dfs()
{
    stack<int>st;
    st.push(1);
    visited[1]=1;
    paren[1]=1;
    map<int,int>mp;
    while (!st.empty())
    {
        int t=st.top();
        set<int,greater<int>>s;
        int p=0;
        for(auto a:graph[t])
        {
            if(visited[a]==0)
            {
                p++;
                s.insert(a);
                visited[a]=1;
                paren[a]=t;
            }
        }
        if(p==0)
        {
            if(mp[t]==0)
            {
                cout<<t<<" "<<paren[t]<<" ";
            }
            else 
            {
                if(paren[t]!=t)cout<<paren[t]<<" ";
            }
              st.pop();
        }
        else 
        {
            for(auto x:s)st.push(x);
            cout<<t<<" ";
            mp[t]=1;
        }
    }
}
void solve()
{
   int n;
   cin>>n;
   string s;
   cin>>s;
   int ar[10];
   for(int i=1;i<=9;i++)cin>>ar[i];
   for(int i=0;i<n;i++)
   {
       if(ar[s[i]-'0']>(s[i]-'0'))
       {
           while(i<n&&ar[s[i]-'0']>=(s[i]-'0'))
           {
               s[i]=ar[s[i]-'0']+'0';
               i++;
           }
           break;
       }
   }
   cout<<s<<endl;
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int tc;
    // cin>>tc;
    // while(tc--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}