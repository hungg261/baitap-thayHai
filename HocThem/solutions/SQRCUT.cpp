/******************************************************************************
Link: SQRCUT
Code: SQRCUT
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-13-20.48.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int h,w;

bool check(double mid){
    int h_cnt=h/mid,w_cnt=w/mid;
    return h_cnt*w_cnt>=3;
}

void solve(){
    double l=0.0001,h=1e6,res=0.0001;
    while(h-l>=0.0001){
        double mid=(l+h)/2;
        if(check(mid)){
            res=mid;
            l=mid+0.0001;
        }
        else h=mid-0.0001;
    }

    cout<<fixed<<setprecision(3)<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("SQRCUT.INP","r",stdin);
    freopen("SQRCUT.OUT","w",stdout);
    cin>>h>>w;
    solve();

    return 0;
}
