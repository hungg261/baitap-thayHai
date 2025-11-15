/******************************************************************************
Link: MAXSUM
Code: MAXSUM
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-14.35.58
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[1005][1005],dp[1005][1005];

void solve(){
    if(a[1][1]%2==0)dp[1][1]=a[1][1];
    for(int i=2;i<=n;++i){
        dp[i][1]=dp[i-1][1];
        if(a[i][1]%2==0)dp[i][1]+=a[i][1];
    }
    for(int i=2;i<=m;++i){
        dp[1][i]=dp[1][i-1];
        if(a[1][i]%2==0)dp[1][i]+=a[1][i];
    }

    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i][j]%2==0){
                dp[i][j]+=a[i][j];
            }
        }
    }
    cout<<dp[n][m]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MAXSUM.INP","r",stdin);
    freopen("MAXSUM.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }

    solve();
    return 0;
}
