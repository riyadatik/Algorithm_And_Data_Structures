#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,int>
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define DIST (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define LL long long int
#define MOD 1000000007
LL dp[1005][1005];
LL NCR(LL n, LL r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r];
    else
    {
        dp[n][r]=(NCR(n-1,r)%MOD+NCR(n-1,r-1)%MOD)%MOD;
        return dp[n][r];
    }
}
int main()
{
    LL n, r;
    cin>>n>>r;
    for(int i=0; i<1005; i++)
    {
        for(int j=0; j<1005; j++)
        {
            dp[i][j]=-1;
        }
    }
    LL ans=NCR(n, r);
    cout<<ans;
    return 0;
}
