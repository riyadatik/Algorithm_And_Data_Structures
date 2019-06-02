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
int par[10005];

int Find(int x)
{
    if(par[x]==x) return x;

    return par[x]=Find(par[x]);
}

void Union(int a, int b)
{
    //par[Find(b)]=Find(a);
    int u=Find(a);
    int v=Find(b);
    if(u==v)
        printf("They are already friends");
    else
        par[u]=v;
}
int main()
{
    int n, m, i, a, b;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        par[i]=i;
    }
    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&a,&b);
        Union(a, b);
    }
    return 0;
}
