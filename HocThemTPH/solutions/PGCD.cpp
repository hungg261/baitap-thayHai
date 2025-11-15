/******************************************************************************
Link: PGCD
Code: PGCD
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-22-10.41.45
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int k,n;
void solve(){
    cin>>k>>n;
    int ans=0;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        int low=cur-cur%k,high=low+k;
        int target,diff;
        if(low==0||high-cur<=cur-low){
            target=high;
            diff=high-cur;
        }
        else{
            target=low;
            diff=cur-low;
        }
        ans+=diff;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PGCD.INP","r",stdin);
    freopen("PGCD.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}
