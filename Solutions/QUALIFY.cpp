// BT_HungPhan_03102025
/******************************************************************************
Link: QUALIFY
Code: QUALIFY
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-17-19.59.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3,MAXVAL=1e6;
int n,a[MAXN+5];

int divcnt[MAXVAL+5];
void compute(){
    for(int i=1;i<=MAXVAL;++i){
        for(int j=i;j<=MAXVAL;j+=i){
            ++divcnt[j];
        }
    }
}

int dp[MAXN+5],ans=-1;
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    for(int i=1;i<=n;++i){
        dp[i]=1;
        for(int j=1;j<i;++j){
            if(a[j]!=a[i]&&divcnt[a[j]]==divcnt[a[i]]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }

        ans=max(ans,dp[i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("QUALIFY.INP","r",stdin);
    freopen("QUALIFY.OUT","w",stdout);
    int t;
    cin>>t;

    compute();
    while(t--){
        solve();
    }
    cout<<ans<<'\n';
    return 0;
}
