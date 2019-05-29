#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,int>
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define DIST (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define LL long long int
#define MOD 1000000007
LL bigmod(LL N, LL P)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        LL res=bigmod(N,P/2);
        return ((res%MOD)*(res%MOD))%MOD;
    }
    else
    {
        return ((N%MOD)*bigmod(N,P-1)%MOD)%MOD;
    }
}
int main()
{
    LL n, p, ans;
    cin>>n>>p;
    ans=bigmod(n, p);
    cout<<ans;
    return 0;
}
