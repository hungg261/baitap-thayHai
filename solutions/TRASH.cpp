/******************************************************************************
Link: TRASH
Code: TRASH
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-01-09.31.14
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int a[MAXN+1],prefix[MAXN+1],n,t;

void solve(){
    int ans=0;
    for(int i=1;i<=n;++i){
        int low=lower_bound(prefix,prefix+i,prefix[i]-t)-prefix;
        ans+=i-low;
    }

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TRASH.INP","r",stdin);
    freopen("TRASH.OUT","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }

    solve();
    return 0;
}
