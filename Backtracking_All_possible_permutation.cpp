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
int used[100], number[100];
void permutation(int pos, int n)
{
    if(pos==n+1)
    {
        for(int i=1; i<=n; i++)
        {
            printf("%d ",number[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(used[i]==0)
        {
            used[i]=1;
            number[pos]=i;
            permutation(pos+1, n);
            used[i]=0;
        }
    }
}
int main()
{
    int n, i, j;
    scanf("%d",&n);
    permutation(1, n);
    return 0;
}
