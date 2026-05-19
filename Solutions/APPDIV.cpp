// BT_HungPhan_03102025
/******************************************************************************
Link: APPDIV
Code: APPDIV
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-02-20.55.24
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=20;
int n,a[MAXN+5];

int ans=1e18,total=0;
void solve(){
    for(int mask=0;mask<(1<<n);++mask){
        int sum=0;
        for(int i=1;i<=n;++i){
            if(mask&(1<<(i-1))){
                sum+=a[i];
            }
        }

        ans=min(ans,abs(total-2*sum));
    }

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("APPDIV.INP","r",stdin);
    freopen("APPDIV.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        total+=a[i];
    }

    solve();
    return 0;
}
