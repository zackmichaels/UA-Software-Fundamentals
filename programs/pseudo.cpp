#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1000009],res=0;
bool chek[10000009];
void sieve()
{
    for(int i=2;i*i<=100009;i++)
    {
        for(int j=i*i;j<=100009;j++)
        {
            chek[j]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cout<<"Prime check"<<endl;
    cin>>n;
    if(a[n]) cout<<"Is a prime";
    else cout<<"Is not a prime";


}