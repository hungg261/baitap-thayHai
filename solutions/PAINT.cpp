/******************************************************************************
Link: PAINT
Code: PAINT
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-12.39.39
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int cost[21][3],n,dp[21][3];

void solve(){
    for(int i=0;i<3;++i){
        dp[1][i]=cost[1][i];
    }

    for(int i=2;i<=n;++i){
        for(int j=0;j<3;++j){
            for(int k=0;k<3;++k){
                if(k==j)continue;

                dp[i][j]=min(dp[i][j],dp[i-1][k]+cost[i][j]);
            }
        }
    }
    cout<<*min_element(dp[n],dp[n]+3)<<'\n';
}

void input(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=0;j<3;++j){
            cin>>cost[i][j];
        }
    }

    memset(dp,1,sizeof(dp));
    solve();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        input();
    }
    return 0;
}
