/******************************************************************************
Link: LIGHT
Code: LIGHT
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-10-21.57.34
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LIGHT.INP","r",stdin);
    freopen("LIGHT.OUT","w",stdout);
    int n;
    cin>>n;

    cout<<(1LL<<(__builtin_popcountll(n)-1))<<'\n';
    return 0;
}
