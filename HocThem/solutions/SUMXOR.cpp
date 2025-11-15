/******************************************************************************
Link: SUMXOR
Code: SUMXOR
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-25-19.11.07
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

int n,a[1000005],
    bitmask[31];

void solve(){
    int ans=0;
    for(int mask=0;mask<=30;++mask){
        int bit=(1<<mask),
            cnt1=0,cnt0=0;
        for(int i=1;i<=n;++i){
            if(a[i]&bit)++cnt1;
            else ++cnt0;
        }
        ans+=cnt1*cnt0*bit;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SUMXOR.INP","r",stdin);
    freopen("SUMXOR.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
