// BT_HungPhan_03102025
/******************************************************************************
Link: GOLD
Code: GOLD
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-23-20.38.37
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1000,MAXS=5e6;
const int MOD=1e9+7;
int n,S,dp[MAXS+5];
bool mark[MAXS+5];

void solve(){
    cin>>n>>S;

    dp[0]=1;
    mark[0]=true;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        for(int j=S;j>=cur;--j){
            (dp[j]+=dp[j-cur])%=MOD;
            mark[j]|=mark[j-cur];
        }
    }

    for(int i=S;i>=1;--i){
        if(mark[i]){
            cout<<i<<'\n'<<dp[i]<<'\n';
            return;
        }
    }
    cout<<"0\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GOLD.INP","r",stdin);
    freopen("GOLD.OUT","w",stdout);
    solve();

    return 0;
}
