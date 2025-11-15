/******************************************************************************
Link: RFILE
Code: RFILE
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-17-17.09.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    unordered_set<int>mark;
    mark.insert(0);
    int ans=0;
    for(int i=0;i<n;++i){
        int cur;
        cin>>cur;

        if(!mark.count(cur-1))++ans;
        mark.insert(cur);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("RFILE.INP","r",stdin);
    freopen("RFILE.OUT","w",stdout);
    solve();

    return 0;
}
