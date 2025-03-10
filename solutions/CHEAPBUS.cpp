/******************************************************************************
Link: CHEAPBUS
Code: CHEAPBUS
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-16-09.05.19
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int cost[11],dp[11][151];

void trace(int target){
    int chosen=10,
        purchased=dp[chosen][target];

    while(target>0){
        while(dp[chosen][target]==purchased){
            --chosen;
        }

        ++chosen;
        target-=chosen;
        purchased=dp[chosen][target];

        cout<<chosen<<'\n';
    }
}

void solve(int n){
    memset(dp,63,sizeof dp);
    dp[0][0]=0;
    for(int idx=1;idx<=10;++idx){
        for(int distance=0;distance<=n;++distance){
            for(int i=0;i<=distance;++i){
                dp[idx][distance]=min(dp[idx][distance],dp[idx-1][distance-idx*i]+cost[idx]*i);
            }
        }
    }

    trace(n);
    cout<<dp[10][n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CHEAPBUS.INP","r",stdin);
    freopen("CHEAPBUS.OUT","w",stdout);
    for(int i=1;i<=10;++i){
        cin>>cost[i];
    }

    int n;
    cin>>n;

    solve(n);
    return 0;
}
