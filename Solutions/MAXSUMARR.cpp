/******************************************************************************
Link: MAXSUMARR
Code: MAXSUMARR
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-06-20.34.07
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6;
int a[MAX+1],n;

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    int prefix=0,
        ans=-1;
    for(int i=1;i<=n;++i){
        prefix+=a[i-1];
        ans=max(ans,a[i]*(n-i+1)-prefix);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MAXSUMARR.INP","r",stdin);
    freopen("MAXSUMARR.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
