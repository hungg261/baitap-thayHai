/******************************************************************************
Link: BOARD
Code: BOARD
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-02-20.52.37
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e5;
int n;
struct pos{
    int u,v;
} a[MAX+1];

bool op(pos&a,pos&b){
    return a.u<b.u;
}

int dp[MAX+1],len=0;
void solve(){
    dp[len++]=a[0].v;
    for(int i=1;i<n;++i){
        if(a[i].v>dp[len-1]){
            dp[len++]=a[i].v;
        }
        else{
            dp[lower_bound(dp,dp+len,a[i].v)-dp]=a[i].v;
        }

    }

//    for(int i=0;i<len;++i){
//        cout<<dp[i]<<' ';
//    }cout<<'\n';

    cout<<len<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BOARD.INP","r",stdin);
    freopen("BOARD.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].u>>a[i].v;
        a[i].v*=-1;
    }

    sort(a,a+n,op);
//    for(int i=0;i<n;++i){
//        cout<<a[i].u<<' '<<a[i].v<<'\n';
//    }

    solve();
    return 0;
}
