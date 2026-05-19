// BT_HungPhan_03102025
/******************************************************************************
Link: PLANTING
Code: PLANTING
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-20-20.07.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
int L,n;
multiset<int>ms;
multiset<int>results;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PLANTING.INP","r",stdin);
    freopen("PLANTING.OUT","w",stdout);
    cin>>L>>n;
    ms.insert(0);
    ms.insert(L);
    results.insert(L);

    while(n--){
        int cur;
        cin>>cur;

        auto high=ms.upper_bound(cur);
        auto low=prev(high);
        ms.insert(cur);

        results.erase(results.find(*high-*low));
        results.insert(*high-cur);
        results.insert(cur-*low);

        cout<<(*results.rbegin())<<' ';
    }
    return 0;
}
