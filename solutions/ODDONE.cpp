/******************************************************************************
Link: ODDONE
Code: ODDONE
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-08-20.02.09
*******************************************************************************/
#include<bits/stdc++.h>
#define left sussybaka
#define right amongus
#define int long long
using namespace std;

const int MAX=1e5;
int a[MAX+5],left[MAX+5],right[MAX+5],n;

void compute(){
    for(int i=1;i<=n;++i){
        left[i]=__gcd(left[i-1],a[i]);
    }

    for(int i=n;i>=1;--i){
        right[i]=__gcd(right[i+1],a[i]);
    }
}

void solve(){
    if(n==1){
        cout<<a[1]+1<<'\n';
        return;
    }

    int res=-1;
    for(int i=1;i<=n;++i){
        int cur_gcd=__gcd(left[i-1],right[i+1]);
        if(cur_gcd!=0&&a[i]%cur_gcd!=0){
            res=cur_gcd;
        }
    }
    cout<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ODDONE.INP","r",stdin);
    freopen("ODDONE.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    compute();
    solve();
    return 0;
}
