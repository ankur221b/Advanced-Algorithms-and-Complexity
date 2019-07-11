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

map<int,int> get(int residual[MAX][MAX],int n,int m)
{
  map<int,int> match;

  for(int i=0;i<=n+m+1;i++)
  {
      match[i]=-1;
      for(int j=0;j<=m+n+1;j++)
      {
          if(residual[j][i]==1)match[i]=j-n;
          //cout<<residual[i][j]<<" ";
      }
      //cout<<endl;
  } 


  return match;
}

bool bfs(int residual[MAX][MAX],int src,int sink,int* parent)
{
  bool visited[sink+1]={0};
  int u;
  queue<int>q;
  q.push(src);
  visited[src]=1;
  parent[src]=-1;

  while(!q.empty())
  {
    u = q.front();
    q.pop();

    for(int v=0;v<=sink;v++)
    {
      if(!visited[v] && residual[u][v]>0)
      {
        q.push(v);
        parent[v]=u;
        visited[v]=1;
      }
    }
  }

  return visited[sink];
}

map<int,int> edmund_karp(int edges[MAX][MAX],int src, int sink,int n,int m)
{
  int residual[MAX][MAX],u;

  for(int i=0;i<MAX;i++)
  {
    for(int j=0;j<MAX;j++)residual[i][j] = edges[i][j];
  }

    int* parent = new int[sink+1]; 
    int max_flow=0;
    for(int i=0;i<=sink;i++)parent[i]=-2;
   

    while(bfs(residual,src,sink,parent))
    {
      int flow_path = INT_MAX;

      for(int v=sink;v!=src;v=parent[v])
      {
        u=parent[v];
        flow_path = min(flow_path, residual[u][v]);
      }

      for(int v=sink;v!=src;v=parent[v])
      {
        u=parent[v];
        residual[u][v] -= flow_path;
        residual[v][u] += flow_path;
      }

      max_flow += flow_path;
    }

    map<int,int> mm = get(residual,n,m);
    //cout<<max_flow<<endl;
    for(int i=1;i<=n;i++)
    {
        if(mm[i]>0)cout<<mm[i]<<" ";
        else cout<<"-1 ";
    }


}

int main()
{
  int n,m,x;
  cin>>n>>m;
  int edges[MAX][MAX];
    map<int,int> map;

  for(int i=1;i<MAX;i++)
  {
    for(int j=1;j<MAX;j++)edges[i][j]=0;
  }

    for(int i=1;i<=n;i++)edges[0][i]=1;

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin>>x;
        edges[i][n+j]=x;
      }
    }

    
    for(int i=n+1;i<=n+m;i++)edges[i][n+m+1]=1;

    edmund_karp(edges,0,n+m+1,n,m);

    
  
  

  return 0;
}


 



    
  
