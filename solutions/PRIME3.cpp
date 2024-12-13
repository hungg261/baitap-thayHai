/******************************************************************************
Link: PRIME3
Code: PRIME3
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-23-18.47.28
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define insert(Q,pos,value) Q[pos].a[Q[pos].len++]=value;
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

bool ktsnt(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0)return false;
    }
    return true;
}

const int MOD=1e9+9;
int dp[10005][905],P[900],p,n;
void solve(){
    for(int i=100;i<=999;++i){
        if(ktsnt(i))dp[3][i]=1,P[p++]=i;
    }

    for(int i=4;i<=n;++i){
        for(int pr=0;pr<p;++pr){
            for(int j=1;j<=9;++j){
                int pos=(P[pr]%100)*10+j;
                if(ktsnt(pos))dp[i][P[pr]]+=dp[i-1][pos]%MOD;
            }
        }
    }

    int ans=0;
    for(int i=0;i<p;++i){
        ans=(ans%MOD+dp[n][P[i]]%MOD)%MOD;
    }
    cout<<ans%MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PRIME3.INP","r",stdin);
    freopen("PRIME3.OUT","w",stdout);
    cin>>n;
    solve();

    return 0;
}
