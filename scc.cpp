#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int, int>
#define sc scanf
#define pf printf
#define pb push_back
#define uu first
#define vv second
#define DIST(x1,y1,x2,y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
vector<int>G[10005];
int dsc[10005], low[10005], onstk[10005], scc[10005];
stack<int>stk;
int c, cnt;
int vis[10005], ind[10004];
void tarjan(int u)
{
    c++;
    dsc[u]=c;
    low[u]=c;
    stk.push(u);
    onstk[u]=1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(dsc[v]==-1)
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(onstk[v])
        {
            low[u]=min(dsc[v],low[u]);
        }
    }
    if(low[u]==dsc[u])
    {
        cnt++;
        int v;
        do{
            v=stk.top();
            stk.pop();
            scc[v]=cnt;
            onstk[v]=0;
        }while(u!=v);
    }
}
int main()
{
    int n, m, i, j, k;
    mem(dsc,-1);
    cin>>n>>m;
    for(i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        G[u].pb(v);
    }
    for(i=1; i<=n; i++)
    {
        c=0;
        if(dsc[i]==-1)
        {
            tarjan(i);
        }
    }
    for(i=1; i<=n; i++)
    {
        cout<<scc[i]<<' ';
    }
    return 0;
}
