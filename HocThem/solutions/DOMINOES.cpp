/******************************************************************************
Link: DOMINOES
Code: DOMINOES
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-04-21.20.22
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

unordered_map<int,int>dp;
int n;
struct domino{
    int a,b;
} A[100005];

bool op(domino&m,domino&n){
    if(m.b==n.b)return m.a<n.a;
    return m.b<n.b;
}

int solve(){
    for(int i=0;i<n;++i){
        dp[A[i].b]=max(dp[A[i].b],dp[A[i].a]+1);
    }

    int ans=0;
    for(auto p:dp){
        ans=max(ans,p.nd);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DOMINOES.INP","r",stdin);
    freopen("DOMINOES.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)cin>>A[i].a>>A[i].b;
    sort(A,A+n,op);

    cout<<solve();
    return 0;
}
