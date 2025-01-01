/******************************************************************************
Link: NUMTRIS
Code: NUMTRIS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-10-21.45.42
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INV2=500000004, MOD=1e9+7;
int powmod(int a,int b,int m){
    int res=1;
    a%=m;

    while(b>0){
        if(b%2==1)res=(res*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;

    int ans=(1+(4*((powmod(3,n,MOD)-1)*INV2)%MOD)%MOD)%MOD;
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("NUMTRIS.INP","r",stdin);
    freopen("NUMTRIS.OUT","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
