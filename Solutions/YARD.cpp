/******************************************************************************
Link: YARD
Code: YARD
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-20.57.42
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[41]={0,1,1,1,2},
    res[217287];
bool P[217287];
void compute(){
    for(int i=5;i<=40;++i){
        dp[i]=dp[i-1]+dp[i-4];
    }

    for(int i=2;i*i<=217286;++i){
        if(!P[i]){
            for(int j=i*i;j<=217286;j+=i){
                P[j]=true;
            }
        }
    }
    for(int i=2;i<=217286;++i){
        res[i]=res[i-1];
        if(!P[i])++res[i];
    }
}

void solve(){
    int n;
    cin>>n;

    cout<<res[dp[n]]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("YARD.INP","r",stdin);
    freopen("YARD.OUT","w",stdout);
    compute();
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
