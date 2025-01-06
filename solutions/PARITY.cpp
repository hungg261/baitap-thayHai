/******************************************************************************
Link: PARITY
Code: PARITY
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-21-21.42.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n,P[100005];
void solve(){
    unordered_map<int,int>Q;
    Q[0]=1;
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=Q[P[i]];
        ++Q[P[i]];
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PARITY.INP","r",stdin);
    freopen("PARITY.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        int cur;
        cin>>cur;
        P[i+1]=P[i]+(cur%2==0?1:-1);
    }

    solve();
    return 0;
}
