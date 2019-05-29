#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000];
    int i, k, rem=0;
    cin>>a>>k;
    for(i=0; i<strlen(a); i++)
    {
        int digit=a[i]-'0';
        rem=(rem*10+digit)%k;
    }
    if(rem==0)
    {
        printf("the number is divisible by %d",k);
    }
    return 0;
}
