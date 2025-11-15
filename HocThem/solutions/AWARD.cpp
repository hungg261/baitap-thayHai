/******************************************************************************
Link: AWARD
Code: AWARD
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-30-20.20.03
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

const int MAX=1e3+5;
int A[MAX],dp[MAX],n;

int solve(){
    for(int i=0;i<n;++i){
        dp[i]=A[i];
        for(int j=0;j<i;++j){
            if(A[i]>A[j])dp[i]=max(dp[i],dp[j]+A[i]);
        }
    }
    return *max_element(dp,dp+n);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("AWARD.INP","r",stdin);
    freopen("AWARD.OUT","w",stdout);
    cin>>n;
    inp(A,n);

    cout<<solve();
    return 0;
}
