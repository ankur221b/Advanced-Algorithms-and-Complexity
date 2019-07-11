#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 250
#define MOD 1000000007
#define mod 100000

struct node
{
  int weight;
  vector<int> children;
};

int solve(vector<node>& v,int vertex,vector<int>& s,int parent)
{
  if(s[vertex]==-1)
  {
    if(v[vertex].children.empty())s[vertex]=v[vertex].weight;
  
    else
    {
      int ma1 = v[vertex].weight;

      for(auto u:v[vertex].children)
      {
        if(u==parent)continue;

        for(auto w:v[u].children)
        {
          if(w!=vertex)ma1 += solve(v,w,s,u);
        }
      }

      int ma2=0;

      for(auto u:v[vertex].children)
      {
        if(u!=parent)ma2 += solve(v,u,s,vertex);
      }
      s[vertex] = max(ma1,ma2);
    }
  }
  return s[vertex];
}


int main()
{
  fast_io;
  int n,a,b;
  cin>>n;

  vector<node> v(n);
  vector<int> s(n,-1);
  
  for(int i=0;i<n;i++)cin>>v[i].weight;

  for(int i=0;i<n-1;i++)
  {
    cin>>a>>b;
    v[a-1].children.push_back(b-1);
    v[b-1].children.push_back(a-1);
  }

  cout<<solve(v,0,s,-1);





  return 0;
}


 



    
  
