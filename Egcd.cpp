#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,int>
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define DIST (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define LL long long int
#define MOD 1000000007
int x, y;
int egcd(int a, int b)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int d=egcd(b,a%b);
    int x1=y;
    int y1=x-((a/b)*y);
    x=x1;
    y=y1;
    return d;
}
int main()
{
    int n, m;
    cin>>n>>m;
    int ans=egcd(n, m);
    cout<<ans;
    return 0;
}
