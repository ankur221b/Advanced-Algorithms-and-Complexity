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
#define MAX 101
#define MOD 1000000007
#define mod 100000

bool bfs(int residual[MAX][MAX],int src,int sink,int parent[])
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

        for(int v=1;v<=sink;v++)
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

int edmund_karp(int edges[MAX][MAX],int src, int sink)
{
    int residual[MAX][MAX],u;

    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<MAX;j++)residual[i][j] = edges[i][j];
    }

    int parent[sink+1], max_flow=0;
   

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
    

    return max_flow;

}

int main()
{
    int n,m,u,v,w;
    cin>>n>>m;
    int edges[MAX][MAX];

    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<MAX;j++)edges[i][j]=0;
    }

    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        edges[u][v]+=w;
    }

    int max_flow = edmund_karp(edges,1,n);

    cout<<max_flow;
    
    

    return 0;
}


 



    
  
