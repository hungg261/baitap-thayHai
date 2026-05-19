// BT_HungPhan_05282025
/******************************************************************************
Link: ORANGES
Code: ORANGES
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-28-19.33.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ORANGES.INP","r",stdin);
    freopen("ORANGES.OUT","w",stdout);
    long long n;
    cin >> n;

    cout << (n + 1) * (n + 2) / 2 - 1 << '\n';
    return 0;
}
