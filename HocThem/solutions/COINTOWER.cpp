/******************************************************************************
Link: COINTOWER
Code: COINTOWER
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-19-19.44.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int K,L,dp[1000005];
void solve(int n){
    memset(dp,0,sizeof(dp));
    dp[1]=true;
    for(int i=2;i<=n;++i){
        if(!dp[i-1])dp[i]=true;
        if(i>=K&&!dp[i-K])dp[i]=true;
        if(i>=L&&!dp[i-L])dp[i]=true;
    }
    cout<<(dp[n]?'A':'B');
}

void input(){
    int m;
    cin>>K>>L>>m;
    for(int i=1;i<=m;++i){
        int cur;
        cin>>cur;

        solve(cur);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("COINTOWER.INP","r",stdin);
    freopen("COINTOWER.OUT","w",stdout);
    input();

    return 0;
}
