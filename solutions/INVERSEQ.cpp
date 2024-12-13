/******************************************************************************
Link: INVERSEQ
Code: INVERSEQ
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-21-15.37.16
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

int pow2(int n){
    int r=1;
    while(r*2<n)
        r*=2;
    return r;
}

int solve(int n){
    if(n==1)return 0;

    int l=pow2(n);
    if(n>l)return !solve(n-l);
    return solve(n);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("INVERSEQ.INP","r",stdin);freopen("INVERSEQ.OUT","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<solve(n)<<endl;
    }

    return 0;
}
