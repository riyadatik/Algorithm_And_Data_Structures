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
int n, k;
int number[20];
void combination(int pos, int last)
{
    if(pos==k+1)
    {
        for(int i=1; i<=k; i++)
        {
            printf("%d ",number[i]);
        }
        printf("\n");
        return;
    }
    for(int i=last+1; i<=n-k+pos; i++)
    {
        number[pos]=i;
        combination(pos+1, last);
    }
}
int main()
{
    scanf("%d %d",&n, &k);
    combination(1, 0);
    return 0;
}
