// BT_HungPhan_03102025
/******************************************************************************
Link: BPAIRS
Code: BPAIRS
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-24-19.25.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3,MAXVAL=1e3;
int mark1[MAXVAL+5],mark2[MAXVAL+5],n;

void solve(){
    int ans=0;
    bool changed=false;
    for(int i=1;i<=MAXVAL;++i){
        ans+=min(mark1[i],mark2[i]);
        if(!changed&&mark2[i]<mark1[i]){
            ++ans;
            changed=true;
        }
    }
    if(!changed)--ans;

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BPAIRS.INP","r",stdin);
    freopen("BPAIRS.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        ++mark1[cur];
    }

    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        ++mark2[cur];
    }

    solve();
    return 0;
}
