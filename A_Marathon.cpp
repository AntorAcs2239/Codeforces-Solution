#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   int ans=0;
   if(b>a)ans++;
   if(c>a)ans++;
   if(d>a)ans++;
   cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}