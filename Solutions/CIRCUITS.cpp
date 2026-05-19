// BT_HungPhan_03102025
/******************************************************************************
Link: CIRCUITS
Code: CIRCUITS
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-17-20.10.15
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e3;
int m,n,a[MAX+5],b[MAX+5];

int dp[MAX+5][MAX+5];
void solve(){
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[m][n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CIRCUITS.INP","r",stdin);
    freopen("CIRCUITS.OUT","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;++i){
        cin>>a[i];
        a[i]=__builtin_popcountll(a[i]);
    }
    for(int i=1;i<=n;++i){
        cin>>b[i];
        b[i]=__builtin_popcountll(b[i]);
    }

    solve();
    return 0;
}
