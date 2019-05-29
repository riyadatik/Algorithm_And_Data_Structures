#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;
#define pii pair<int, int>
#define piii pair<pii, pii>
#define mem(x,y) memset(x,y,sizeof(x))
#define sc scanf
#define pf printf
#define pb push_back
#define pu push
#define uu first
#define vv second
#define DIST(x1,y1,x2,y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define pi acos(-1)
#define ull unsigned long long int
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
vector<int>G[100005];
int level[100005], visited[100005], par[100005];
int n, m;
void dfs(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!visited[v])
        {
            visited[v]=1;
            dfs(v);
        }
    }
}
int main()
{
    int i, src;
    scanf("%d %d",&n, &m);
    for(i=1; i<=m; i++)
    {
        int u, v;
        scanf("%d %d",&u, &v);
        G[u].pb(v);
        //G[v].pb(u);
    }
    scanf("%d",&src);
    par[src]=-1;
    level[src]=0;
    visited[src]=1;
    dfs(src);
    for(i=1; i<=n; i++)
    {
        printf("source = %d destination = %d distance = %d\n",src,i,level[i]);
    }
    return 0;
}
