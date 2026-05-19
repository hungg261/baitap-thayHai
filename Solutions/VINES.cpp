// BT_HungPhan_03102025
/******************************************************************************
Link: VINES
Code: VINES
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-09-19.21.53
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5;
int n, d;
pair<int,int> a[MAXN+5];


void solve(){
    int high = a[1].second;
    for(int i = 2; i <= n; ++i){
        if(a[i].first <= high){
            high = max(high, a[i].second);
        }
        else{
            break;
        }
    }

    cout << min(high/d, n) << '\n'; // chi co toi da n day leo de treo qua :<
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("VINES.INP","r",stdin);
    freopen("VINES.OUT","w",stdout);
    cin >> n >> d;
    for(int i = 1; i <= n; ++i){
        int len;
        cin>>len;

        a[i].first = d * i;
        a[i].second = a[i].first + len;
    }

    solve();
    return 0;
}
