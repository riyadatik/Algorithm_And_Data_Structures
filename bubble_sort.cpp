#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[100],i,j,c,n,d;
printf("take a number");
scanf("%d",&n);
printf("take %d integer",n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
for(i=1;i<=n-1;i++)
{
for(j=1;j<=n-1;j++)
{
if(a[j]>a[j+1])
{
c=a[j+1];
a[j+1]=a[j];
a[j]=c;
}
}
}
for(i=1;i<=n;i++)
{
printf("%d",a[i]);
}
return 0;
}
