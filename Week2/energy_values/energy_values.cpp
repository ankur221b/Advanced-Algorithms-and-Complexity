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

void swap_row(vector<vector<double>>& v,int n,int i,int j)
{
  for(int k=0;k<=n;k++)swap(v[i][k],v[j][k]); 
    
}

void forward_elimination(vector<vector<double>>& v,int n)
{
  int max_idx;
  double max_val,factor;

  for(int i=0;i<n;i++)
  {
    max_idx = i;
    max_val = abs(v[max_idx][i]);

    for(int j=i+1;j<n;j++)
    {
      if(abs(v[j][i]) > max_val)
      {
        max_val = abs(v[j][i]);
        max_idx = j;
      }
    }

    swap_row(v,n,i,max_idx);

    for(int j=i+1;j<n;j++)
    {
      factor = v[j][i]/v[i][i];

      for(int k=i;k<=n;k++)
      {
        v[j][k] -= v[i][k]*factor;
      }
    }
  }
}

void back_substitution(vector<vector<double>>& v,int n)
{
  double res[n];

  for(int i=n-1;i>=0;i--)
  {
    res[i] = v[i][n]/v[i][i];

    for(int j=0;j<i;j++)
    {
      v[j][n] -= v[j][i]*res[i];
    }

  }

  for(int i=0;i<n;i++)cout<<fixed<<setprecision(6)<<res[i]<<" ";
}

void gaussian_elimination(vector<vector<double>> v,int n)
{
  forward_elimination(v,n);
  back_substitution(v,n);
}


int main()
{
  int n,m,x;
  cin>>n;
  vector<vector<double>> v(n,vector<double>(n+1));

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      cin>>v[i][j];
    }
  }

  gaussian_elimination(v,n);
  
  

  return 0;
}


 



    
  
