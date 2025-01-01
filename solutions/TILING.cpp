/******************************************************************************
Link: TILING
Code: TILING
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-20.44.08
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[51];
void compute(){
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=50;++i){
        dp[i]=dp[i-1]+2*dp[i-2];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TILING.INP","r",stdin);
    freopen("TILING.OUT","w",stdout);
    compute();
    int n;
    while(cin>>n){
        cout<<dp[n]<<'\n';
    }

    return 0;
}
