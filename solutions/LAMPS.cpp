/******************************************************************************
Link: LAMPS
Code: LAMPS
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-20-14.28.59
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e6+5;
int n,A[MAX]={},B[MAX]={},E[MAX]={};

void solve(){
    B[1]=1;
    for(int i=2;i<n+1;++i){
        if(A[i]==A[i-1])B[i]=B[i-1]+1;
        else B[i]=1;
    }

    E[n]=1;
    for(int i=n-1;i>=1;--i){
        if(A[i]==A[i+1])E[i]=E[i+1]+1;
        else E[i]=1;
    }

    int r=0;
    for(int i=1;i<=n;++i){
        if(A[i-1]==A[i+1])r=max(r,B[i-1]+E[i+1]);
        else r=max({r,B[i-1],E[i+1]});
    }
    cout<<r+1;
//    cout<<endl;
//    for(int i=0;i<n+2;++i)cout<<A[i]<<' ';cout<<endl;
//    for(int i=0;i<n+2;++i)cout<<B[i]<<' ';cout<<endl;
//    for(int i=0;i<n+2;++i)cout<<E[i]<<' ';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("LAMPS.INP","r",stdin);freopen("LAMPS.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>A[i];
    solve();

    return 0;
}
