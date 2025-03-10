/******************************************************************************
Link: MIDGES
Code: MIDGES
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-05-20.05.41
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int n,a[MAXN+1];

void solve(){
    int ans=0,
        movements=0;
    for(int i=n-1;i>=0;){
        auto pos=equal_range(a,a+n,a[i]);

        int range=pos.second-pos.first;
        ans+=max(0LL,a[i]-movements)*range;

        i=pos.first-a-1;
        movements+=range;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MIDGES.INP","r",stdin);
    freopen("MIDGES.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);

    solve();
    return 0;
}
