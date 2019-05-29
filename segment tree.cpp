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
#define mx 100001
int a[mx];
int tree[mx*3];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]=tree[left]+tree[right];
}
void update(int node, int b, int e, int i, int newvalue)
{
    if(i>e || i<b)
        return;
    if(b>=i&&e<=i)
    {
        tree[node]=newvalue;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node]=tree[left]+tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i&&e<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid = (b + e) / 2;
    int p1 = query(left, b, mid, i, j);
    int p2=query(right, mid+1, e, i, j);
    return p1+p2;
}
int main()
{
    int n, i, u, v;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    init(1, 1, n);
    update(1, 1, n, 2, 0);
    scanf("%d %d",&u,&v);
    int ans=query(1, 1, n, u, v);
    printf("%d\n",ans);
    return 0;
}
