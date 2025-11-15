/******************************************************************************
Link: DISTRIBUTION
Code: DISTRIBUTION
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-10-21.23.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n,t[100005];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i];
    }

    int i=1,j=n;
    while(i<j){
        int target=2*t[j];
        while(i+1<j&&t[i]<=target){
            target-=t[i];
            ++i;
        }
        t[i]-=target;
        --j;
    }

    cout<<i<<' '<<n-i<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("DISTRIBUTION.INP","r",stdin);
    freopen("DISTRIBUTION.OUT","w",stdout);
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
