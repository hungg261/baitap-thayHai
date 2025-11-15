/******************************************************************************
Link: ANDO
Code: ANDO
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-20-20.07.55
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

int n,a[300005];
int bitmask[31];
void solve(){
    for(int i=1;i<=n;++i){
        for(int mask=0;mask<=30;++mask){
            if(a[i]&(1<<mask)){
                ++bitmask[mask];
            }
        }
    }
    int ans=0;
    for(int mask=30;mask>=0;--mask){
        int temp=ans|(1<<mask),
            cnt=0;
        for(int i=1;i<=n;++i){
            if((a[i]&temp)==temp){
                ++cnt;
            }
        }
        if(cnt>=2)ans=temp;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ANDO.INP","r",stdin);
    freopen("ANDO.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
