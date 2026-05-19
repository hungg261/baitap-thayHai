// BT_HungPhan_03102025
/******************************************************************************
Link: ELEMENT
Code: ELEMENT
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-17-20.45.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=5000;
int a[MAXN+5],n;

void solve(){
    unordered_set<int>freq;
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(freq.count(a[i]-a[j])){
                ++ans;
                break;
            }
        }

        for(int j=1;j<=i;++j){
            freq.insert(a[i]+a[j]);
        }
    }

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ELEMENT.INP","r",stdin);
    freopen("ELEMENT.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
