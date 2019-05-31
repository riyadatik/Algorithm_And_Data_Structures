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
int mark[1000006], phi[1000006];
void sieve(int n)
{
    int i, j, sq;
    sq=sqrt(n);
    mark[1]=1;
    for(i=4; i<=n; i=i+2)
        mark[i]=1;
    for(i=3; i<=sq; i++)
    {
        if(mark[i]==0)
        {
            for(j=i*i; j<=n; j=j+i+i)
            {
                mark[j]=1;
            }
        }
    }
}
void sievephi(int n)
{
    int i, j;
    for(i=1; i<=n; i++)
        phi[i]=i;

    for(i=2; i<=n; i++)
    {
        if(!mark[i])
        {
            for(j=i; j<=n; j=j+i)
            {
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int main()
{
    int n;
    sieve(1000002);
    scanf("%d",&n);
    sievephi(n);
    printf("%d\n",phi[n]);
    return 0;
}
