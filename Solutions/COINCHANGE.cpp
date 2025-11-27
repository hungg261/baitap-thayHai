/******************************************************************************
Link: COINCHANGE
Code: COINCHANGE
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-09-19.27.27
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

// dp[i] la so cach tra tien cho i dong
int n,m,c[51],dp[251];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("COINCHANGE.INP","r",stdin);
    freopen("COINCHANGE.OUT","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>c[i];
    }

    dp[0]=1;
    for(int i=0;i<m;++i){
        for(int j=c[i];j<=n;++j){
            dp[j]+=dp[j-c[i]];
        }
    }

    cout<<dp[n]<<'\n';
    return 0;
}
