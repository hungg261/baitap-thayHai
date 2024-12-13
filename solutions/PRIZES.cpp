/******************************************************************************
Link: PRIZES
Code: PRIZES
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-19-21.14.38
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

const int MAX=1e5+1;
int A[MAX],P[MAX],L[MAX],R[MAX],n,k;

void compute(){
    L[k]=P[k],
    R[n-k-1]=P[n]-P[n-k];
    for(int i=k+1;i<=n;++i)
        L[i]=max(L[i-1],P[i]-P[i-k]);
    for(int i=n-k+1;i>=0;--i)
        R[i]=max(R[i+1],P[i+k-1]-P[i-1]);
}

int solve(){
    int ans=1e18;
    for(int i=1;i<=n;++i)
        ans=min(ans,max(L[i-1],R[i+k]));
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PRIZES.INP","r",stdin);
    freopen("PRIZES.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>A[i];
        P[i+1]=P[i]+A[i];
    }

    compute();
    cout<<solve();
    return 0;
}
