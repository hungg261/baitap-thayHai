/******************************************************************************
Link: FIB2
Code: FIB2
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-26-16.29.46
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

struct fib{
    int a=0,t=0;
} f[46];
void compute(){
    f[0].a=1,f[1].a=0;
    f[0].t=f[1].t=1;

    for(int i=2;i<=45;++i){
        f[i].a=f[i-1].a+f[i-2].a;
        f[i].t=f[i-1].t+f[i-2].t;
    }
}

int ans;
void solve(int n,int k){
    if(f[n].t==k){
        ans+=f[n].a;
        return;
    }

    if(k<=f[n-2].t){
        solve(n-2,k);
    }
    else{
        ans+=f[n-2].a;
        solve(n-1,k-f[n-2].t);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FIB2.INP","r",stdin);freopen("FIB2.OUT","w",stdout);
    compute();

    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        ans=0;
        solve(n,k);
        cout<<ans<<'\n';
    }
    return 0;
}
