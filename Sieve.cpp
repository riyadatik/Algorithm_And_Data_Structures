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
int a[100005], prime[100005];
int l=1;
void sieve(int n)
{
    int i, j, sq;
    sq=sqrt(n);
    a[1]=1;
    for(i=4; i<=n; i=i+2)
    {
        a[i]=1;
    }
    for(i=3; i<=sq; i++)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=n; j=j+i+i)
            {
                a[j]=1;
            }
        }
    }
    prime[l++]=2;
    for(i=3; i<=n; i=i+2)
    {
        if(a[i]==0)
        {
            prime[l++]=i;
        }
    }
}
int main()
{
    sieve(100002);
    return 0;
}
