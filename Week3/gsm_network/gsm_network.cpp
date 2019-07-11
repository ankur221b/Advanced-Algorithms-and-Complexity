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

vector<vector<int>> clauses;

void init_variable(vector<vector<int>>& variable)
{
  int cntr=1;

  for(int i=0;i<variable.size();i++)
  {
    for(int j=0;j<variable[0].size();j++)
    {
      variable[i][j]=cntr++;
    }

  }

}

void add_exactly_one(vector<int>& v)
{
  clauses.push_back(v);

  for(int i=0;i<v.size();i++)
  {
    for(int j=i+1;j<v.size();j++)
    {
      vector<int> clause;
      clause.push_back(-1*v[i]);
      clause.push_back(-1*v[j]);
      clauses.push_back(clause);
    }
  }
}

void add_vertex_color_constraint(vector<vector<int>>& variable,int vertex_count)
{
  for(int i=0;i<vertex_count;i++)
  {
    add_exactly_one(variable[i]);
  }
}

void add_vertex_edge_constraint(vector<vector<int>>& variable,vector<pair<int,int>>& edges,int color_count)
{
  for(int i=0;i<edges.size();i++)
  {
    int from=edges[i].first, to=edges[i].second;

    for(int j=0;j<color_count;j++)
    {
      vector<int> clause;
      clause.push_back(-1*variable[from][j]);
      clause.push_back(-1*variable[to][j]);
      clauses.push_back(clause);
    }

  }
}

void compute_sat(vector<pair<int,int>>& edges,int n,int m)
{
  int vertex_count=n,color_count=3;
  int variables_count = vertex_count*color_count;

  vector<vector<int>> variable(vertex_count,vector<int>(color_count));

  init_variable(variable);

  add_vertex_color_constraint(variable,vertex_count);
  add_vertex_edge_constraint(variable,edges,color_count);

  cout<<clauses.size()<<" "<<variables_count<<'\n';

  for(int i=0;i<clauses.size();i++)
  {
    for(int j=0;j<clauses[i].size();j++)
    {
      cout<<clauses[i][j]<<" ";
    }
    cout<<"0\n";
  }

}


int main()
{
  int n,m,a,b;
  cin>>n>>m;
  vector<pair<int,int>> edges;
  
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    edges.push_back({a-1,b-1});
  }

  compute_sat(edges,n,m);


  return 0;
}


 



    
  
