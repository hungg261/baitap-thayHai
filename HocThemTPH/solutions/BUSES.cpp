/******************************************************************************
Link: BUSES
Code: BUSES
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-21-21.10.42
*******************************************************************************/
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
using namespace std;

int n,k,a[100005];
void solve(){
    int ans=1e9,arrival=-1,
        minwait=1e9,wait_arrival=-1;
    for(int i=0;i<=k;++i){
        int sum=0,cur_minwait=0;
        for(int j=0;j<n;++j){
            int wait=(k*ceil((a[j]-i)/(double)k)+i)-a[j];
            sum+=wait;
            cur_minwait=max(cur_minwait,wait);
        }
        if(cur_minwait<minwait){
            wait_arrival=i;
            minwait=cur_minwait;
        }
        if(sum<ans){
            arrival=i;
            ans=sum;
        }
    }
    cout<<ans<<' '<<arrival<<'\n';
    cout<<minwait<<' '<<wait_arrival<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BUSES.INP","r",stdin);
    freopen("BUSES.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
