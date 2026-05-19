// BT_HungPhan_03102025
/******************************************************************************
Link: SHIPPING
Code: SHIPPING
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-26-17.35.00
*******************************************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 1e6 + 5;
int n, a[maxN];
int pref[maxN], suf[maxN];

void compute(){
    int s = 0;
    pref[1] = 0;
    for(int i = 2; i <= n; ++i){
        s += a[i - 1];
        pref[i] = pref[i - 1] + s;
    }

    s = 0;
    suf[n] = 0;
    for(int i = n - 1; i >= 1; --i){
        s += a[i + 1];
        suf[i] = suf[i + 1] + s;
    }
}

void solve(){
    compute();
    int ans = 1e18;
    for(int i = 1; i <= n; ++i){
        ans = min(ans, pref[i] + suf[i + 1]);
    }
    for(int i = n; i >= 1; --i){
        ans = min(ans, pref[i - 1] + suf[i]);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SHIPPING.INP", "r", stdin);
    freopen("SHIPPING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    solve();
    return 0;
}
