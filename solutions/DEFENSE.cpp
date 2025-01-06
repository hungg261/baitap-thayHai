/******************************************************************************
Link: DEFENSE
Code: DEFENSE
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-21-20.59.37
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=2e5+5;
int n,a[MAX],dp[MAX],len=0;
void solve(){
    dp[len++]=a[0];
    for(int i=1;i<n;++i){
        if(a[i]>dp[len-1]){
            dp[len++]=a[i];
        }
        else{
            dp[lower_bound(dp,dp+len,a[i])-dp]=a[i];
        }
    }
    cout<<len;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DEFENSE.INP","r",stdin);
    freopen("DEFENSE.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
