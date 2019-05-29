#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int main()
{
    int n, i, j, k, u, v, edge, d;
    int a[100][100];
    cin>>n>>edge;
    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            a[i][j]=MAX;
            if(i==j)
            {
                a[i][j]=0;
            }
        }
    }
    for(i=0; i<edge; i++)
    {
        int n1, n2, cost;
        cin>>n1>>n2>>cost;
        a[n1][n2]=cost;
        a[n2][n1]=cost;
    }
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    return 0;
}
