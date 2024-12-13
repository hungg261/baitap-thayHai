/******************************************************************************
Link: MAXSUBARRAY
Code: MAXSUBARRAY
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-23-23.22.53
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

const int MAX=2e5+1;
int n,A[MAX]={};

void solve(){
    if(n==1){
        cout<<A[0];
        return;
    }
    int maxx=A[0],r=LLONG_MIN;
    for(int i=1;i<n;++i){
        maxx=max(A[i],maxx+A[i]);
        r=max(r,maxx);
    }
    cout<<r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MAXSUBARRAY.INP","r",stdin);freopen("MAXSUBARRAY.OUT","w",stdout);
    cin>>n;
    inp(A,n);

    solve();
    return 0;
}
