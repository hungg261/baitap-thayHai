/******************************************************************************
Link: SCHEDULE
Code: SCHEDULE
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-24-20.54.24
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

const int MAX=1e5+1;
int n;
struct code{
    int s,r;
} A[MAX];

bool op(code&a,code&b){
    return a.r>b.r;
}

void solve(){
    int ans=0,t=0;
    for(int i=0;i<n;++i){
        t+=A[i].s;
        ans=max(ans,t+A[i].r);
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SCHEDULE.INP","r",stdin);freopen("SCHEDULE.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>A[i].s>>A[i].r;
    sort(A,A+n,op);

    solve();
    return 0;
}
