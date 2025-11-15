/******************************************************************************
Link: EXPENSE
Code: EXPENSE
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-09-19.57.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// dp[i]: lieu co the mua bang i dong tien ko
int n,M,c[2001];
bool dp[2001];
void solve(){
    cin>>n>>M;
    for(int i=0;i<n;++i){
        cin>>c[i];
    }
    memset(dp,0,sizeof(dp));

    dp[0]=true;
    for(int i=0;i<n;++i){
        for(int j=1;j<=M;++j){
            if(j-c[i]>=0)dp[j]=dp[j]||dp[j-c[i]];
        }
        if(dp[M])break;
        dp[c[i]]=true;
    }

    for(int i=M;i>=0;--i){
        if(dp[i]){
            cout<<i<<'\n';
            break;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("EXPENSE.INP","r",stdin);
    freopen("EXPENSE.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
