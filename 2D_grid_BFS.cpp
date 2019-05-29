#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define pii pair<int, int>
#define mem(x,y) memset(x,y,sizeof(x))
#define u first
#define v second
int fx[]={+1,-1,+0,-0, -1, -1, +1, +1};
int fy[]={+0,+0,+1,-1, -1, +1, -1, +1};
char G[21][21];
int visited[21][21], level[21][21];
int ans;
int n, m;
void BFS(int a, int b)
{
    ans=0;
    queue<pii>q;
    q.push(pii(a,b));
    visited[a][b]=1;
    level[a][b]=0;
    while(!q.empty())
    {
        pii top=q.front();
        for(int k=0; k<8; k++)
        {
            int tx=top.u+fx[k];
            int ty=top.v+fy[k];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                level[tx][ty]=level[top.u][top.v]+1;
                q.push(pii(tx,ty));
            }
        }
        q.pop();
    }
}
int main()
{
    int t, i, j, k, a, b;
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cin>>G[i][j];
        }
    }
    BFS(1,1);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf("source = (1, 1) destination = (%d, %d) distance = %d\n",i,j,level[i][j]);
        }
    }
    return 0;
}
