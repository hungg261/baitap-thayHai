// BT_HungPhan_03102025
/******************************************************************************
Link: PUMPS
Code: PUMPS
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-17-19.30.58
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int b,d;
    cin>>b>>d;

    int ans=(b-1)*__gcd(b,d)/d;
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PUMPS.INP","r",stdin);
    freopen("PUMPS.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
