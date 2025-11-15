/******************************************************************************
Link: MOD
Code: MOD
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-13.24.00
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a,c,L,R;

bool inside(int x,int L=::L,int R=::R){
    return L<=x&&x<=R;
}

void solve(){
    int n=a-c,
        ans=0;

    if(c>a){
        goto passed;
    }
    if(c==a){
        ans=max(0LL,min(R-L+1,R-a));
        goto passed;
    }
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            if(i>c&&inside(i))++ans;
            if(n/i >c&&inside(n/i))++ans;
            if(i>c&&inside(i)&&i*i==n)--ans;
        }
    }
    passed:
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MOD.INP","r",stdin);
    freopen("MOD.OUT","w",stdout);
    cin>>a>>c>>L>>R;
    solve();

    return 0;
}
