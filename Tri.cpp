#include<bits/stdc++.h>
typedef struct node Node;
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int, int>
#define sc scanf
#define pf printf
#define pb push_back
#define uu first
#define vv second
#define DIST(x1,y1,x2,y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define MAX_NODE 100000
#define MAX_LEN 100
char s[MAX_LEN];
int node[MAX_NODE][26];
int isWord[MAX_NODE];
int sz;
void Insert()
{
    scanf("%s",s);
    //puts(s);
    int len=strlen(s);
    int now=0;
    for(int i=0; i<len; i++)
    {
        if(node[now][s[i]-'a']==0)
        {
            node[now][s[i]-'a']=++sz;
        }
        now=node[now][s[i]-'a'];
    }
    isWord[now]=1;
}
int Search()
{
    scanf("%s",s);
    int curr=0;
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(node[curr][s[i]-'a']==0)
        {
            return 0;
        }
        curr=node[curr][s[i]-'a'];
    }
    return isWord[curr]>0;
}
int main()
{
    int n, i, j, q;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        Insert();
    }
    scanf("%d",&q);
    for(i=1; i<=q; i++)
    {
        if(Search())
        {
            printf("The word is found\n");
        }
        else
        {
            printf("The word is not found\n");
        }
    }
    return 0;
}
