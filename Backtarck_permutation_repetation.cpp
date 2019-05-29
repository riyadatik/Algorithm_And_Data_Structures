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
vector<char>v;
char a[]={'a','a','b','c'};
void permutation()
{
    if(v.size()==3)
    {
        for(int i=0; i<v.size(); i++)
        {
            printf("%c",v[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0; i<4; i++)
    {
        if(!used[i])
        {
            used[i]=1;
            v.pb(a[i]);
            permutation();
            used[i]=0;
            v.pop_back();
            while(a[i]==a[i+1]) i++;
        }
    }
}
int main()
{
    permutation();
    return 0;
}
