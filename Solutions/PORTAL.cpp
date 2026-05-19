// BT_HungPhan_03102025
/******************************************************************************
Link: PORTAL
Code: PORTAL
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-30-19.26.51
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
const int LLMAX = 4e18, LLMIN = -4e18;;
int portals[MAXN+5], n, a, b;

int travel(int portal1, int portal2){
    return llabs(a - portal1) + llabs(b - portal2) + 1;
}

void solve(){
    auto upper1 = lower_bound(portals + 1, portals + n + 1, a);
    auto lower1 = upper1 - 1;

    auto upper2 = lower_bound(portals + 1, portals + n + 1, b);
    auto lower2 = upper2 - 1;

    int ans = b - a;
    ans = min(ans, travel(*lower1, *lower2));
    ans = min(ans, travel(*lower1, *upper2));
    ans = min(ans, travel(*upper1, *lower2));
    ans = min(ans, travel(*upper1, *upper2));

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PORTAL.INP","r",stdin);
    freopen("PORTAL.OUT","w",stdout);
    cin >> a >> b >> n;
    if(a > b) swap(a, b);

    n+=2;
    for(int i = 2; i < n; ++i){
        cin >> portals[i];
    }
    portals[1] = LLMIN;
    portals[n] = LLMAX;
    sort(portals + 1, portals + n + 1);

    solve();
    return 0;
}
