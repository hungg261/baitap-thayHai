// BT_HungPhan_03102025
/******************************************************************************
Link: ALLTRI
Code: ALLTRI
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-24-19.01.49
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=5e5;
int a[MAXN+5],n;

void solve(){
    sort(a+1,a+n+1);

    int low=a[n]-a[1]+1,high=a[1]+a[2]-1;
    cout<<max(0LL,high-low+1);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ALLTRI.INP","r",stdin);
    freopen("ALLTRI.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
