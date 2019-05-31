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
#define mx 10005
struct info{
    int prop, sum;
}tree[mx*3]; //sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ
int a[mx];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].sum=a[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node].sum=tree[left].sum + tree[right].sum;
}
 void update(int node, int b, int e, int i, int j, int x)
 {
     if(e<i || b>j)
        return;
     if(b>=i&&e<=j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
     {
         tree[node].sum = tree[node].sum + ((e-b+1)*x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
         tree[node].prop = tree[node].prop + x; //নিচের নোডগুলোর সাথে x যোগ হবে
         return;
     }
     int left=node*2;
     int right=node*2+1;
     int mid=(b+e)/2;
     update(left, b, mid, i, j, x);
     update(right, mid+1, e, i, j, x);
     tree[node].sum=tree[left].sum + tree[right].sum + (e-b+1) * tree[node].prop;
     //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
     //বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
 }

 int query(int node, int b, int e, int i, int j, int carry)
 {
     if(e<i || b>j)
        return 0;
     if(b>=i&&e<=j)
     {
         return tree[node].sum + carry*(e-b+1); //সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা
     }
     int left=node*2;
     int right=node*2+1;
     int mid=(b+e)/2;
     int p1=query(left, b, mid, i, j, carry+tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
     int p2=query(right, mid+1, e, i, j, carry+tree[node].prop);
     return p1+p2;
 }
int main()
{
    int n, i;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    init(1, 1, n);
    update(1, 1, n, 2, 6, 2);
    update(1, 1, n, 3, 9, 3);
    int ans=query(1, 1, n, 3, 7, 0);
    printf("%d",ans);
    return 0;
}
