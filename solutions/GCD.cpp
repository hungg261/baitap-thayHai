/******************************************************************************
Link: GCD
Code: GCD
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-23-09.21.43
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e5+3;
int n,A[MAX],B[MAX],E[MAX];

void solve(){
    B[0]=A[2],B[n+1]=A[n-1],B[1]=A[1];
    for(int i=2;i<=n;++i){
        B[i]=__gcd(B[i-1],A[i]);
    }

    E[0]=A[2],E[n+1]=A[n-1],E[n]=A[n];
    for(int i=n-1;i>0;--i){
        E[i]=__gcd(E[i+1],A[i]);
    }

    int r=0,idx=0;
    for(int i=1;i<=n;++i){
        int g=__gcd(B[i-1],E[i+1]);
        if(g>r)idx=i,r=g;
    }

    cout<<idx<<' '<<r<<endl;
//    for(int i=0;i<=n+1;++i)cout<<A[i]<<' ';cout<<endl;
//    for(int i=0;i<=n+1;++i)cout<<B[i]<<' ';cout<<endl;
//    for(int i=0;i<=n+1;++i)cout<<E[i]<<' ';cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("GCD.INP","r",stdin);freopen("GCD.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>A[i];

    solve();
    return 0;
}
