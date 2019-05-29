#include<bits/stdc++.h>
using namespace std;
int a[2005], prime[2005], lst[2005], l;
void sieve(int n)
{
    int i, j, sq=sqrt(n+2), sz=0;
    for(i=4; i<=n; i=i+2)
    {
        a[i]=1;
    }
    for(i=3; i<=sq; i=i+2)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=n; j=j+i+i)
            {
                a[j]=1;
            }
        }
    }
    prime[sz++]=2;
    for(i=3; i<=n; i=i+2)
    {
        if(a[i]==0)
        {
            prime[sz++]=i;
        }
    }
}
void prime_fact(int n)
{
    int i, sqn=sqrt(n+2);
    for(i=0; prime[i]<=sqn; i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                lst[l++]=prime[i];
            }
        }
    }
    if(n>1)
    {
        lst[l++]=n;
    }
}
int main()
{
    int i, n;
    sieve(2000);
    cin>>n;
    prime_fact(n);
    for(i=0; i<l; i++)
    {
        cout<<lst[i]<<' ';
    }
    return 0;
}
