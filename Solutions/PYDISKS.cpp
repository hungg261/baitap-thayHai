// BT_HungPhan_03102025
/******************************************************************************
Link: PYDISKS
Code: PYDISKS
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-26-20.52.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6,MAXVAL=1e6;
int a[MAXN+5],n,mark[MAXVAL+5];

void solve(){
    int ans=0;
    for(int i=1;i<=n;++i){
        if(mark[a[i]+1]>0){
            --mark[a[i]+1];
        }
        else{
            ++ans;
        }
        ++mark[a[i]];
    }

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PYDISKS.INP","r",stdin);
    freopen("PYDISKS.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
