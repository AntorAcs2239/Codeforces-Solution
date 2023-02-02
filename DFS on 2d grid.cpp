#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define endl '\n'
#define ld long double
#define mod 1000000007        
#define gcd __gcd
int n,m;
typedef pair<int, int> pi;
int visited[100][100];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
map<int,char>row;
map<int,char>col;
bool isvalid(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)return false;
    if(visited[x][y]==1)return false;
    return true;
}
void dfs(int x,int y)
{
    visited[x][y]=1;
    stack<pair<int,int>>st;
    st.push(make_pair(x,y));
    while(!st.empty())
    {
        int x1=st.top().first;
        int y1=st.top().second;
        bool flag=false;
        if(row[x1]=='R'&&isvalid(x1,y1+1))
        {
            visited[x1][y1+1]=1;
            st.push(make_pair(x1,y1+1));
            flag=true;
        }
        else if(row[x1]=='L'&&isvalid(x1,y1-1))
        {
            visited[x1][y1-1]=1;
            st.push(make_pair(x1,y1-1));
            flag=true;
        }
        if(col[y1]=='U'&&isvalid(x1-1,y1))
        {
            visited[x1-1][y1]=1;
            st.push(make_pair(x1-1,y1));
             flag=true;
        }
        else if(col[y1]=='D'&&isvalid(x1+1,y1))
        {
            visited[x1+1][y1]=1;
            st.push(make_pair(x1+1,y1));
            flag=true;
        }
        if(flag==false)
        {
            st.pop();
        }
    }
}
void position()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
              dfs(i,j);
        }
    }
    dfs(1,2);
}
void solve()
{
    cin>>n>>m;
      row[0]='L';
      row[1]='R';
      row[2]='L';
      row[3]='R';

      col[0]='D';
      col[1]='U';
      col[2]='D';
      col[3]='U';
      col[4]='D';
      col[5]='U';

      position();
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