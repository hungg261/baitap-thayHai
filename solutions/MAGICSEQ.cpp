/******************************************************************************
Link: MAGICSEQ
Code: MAGICSEQ
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-17-21.19.07
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;

    int range=b-a+1,period=range/9,left=range%9;
    int ans=0;
    for(int i=a;i<a+left;++i){
        ans+=(i-1)%9+1;
    }
    ans+=45*period; // 45 = 1+2+3+...+9

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MAGICSEQ.INP","r",stdin);
    freopen("MAGICSEQ.OUT","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
