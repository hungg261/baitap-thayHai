#include<bits/stdc++.h>
using namespace std;

int intrev(int n){
    int r=0;
    while(n>0){
        r=r*10+n%10;
        n/=10;
    }
    return r;
}

int solve(int n){
    return __gcd(n,intrev(n))==1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("NUMFRE.INP","r",stdin);freopen("NUMFRE.OUT","w",stdout);
    int a,b,c=0;cin>>a>>b;
    for(int i=a;i<=b;i++)if(solve(i))c++;
    cout<<c;
    return 0;
}