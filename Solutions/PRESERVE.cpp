// BT_HungPhan_03102025
/******************************************************************************
Link: PRESERVE
Code: PRESERVE
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-09-20.45.01
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int n, k;
multiset<int> ms;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PRESERVE.INP","r",stdin);
    freopen("PRESERVE.OUT","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        ms.insert(cur);
    }

    int ans = 0;
    while(ms.size() > 0){
        ++ans;

        int prev = -k;
        for(;;){
            auto it = ms.upper_bound(prev + k);
            if(it == ms.end()){
                break;
            }

            prev = *it;
            ms.erase(it);
        }
    }

    cout << ans << '\n';
    return 0;
}
