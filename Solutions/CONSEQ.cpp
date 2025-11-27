#include<bits/stdc++.h>
#define int long long
using namespace std;

auto cdpow10(int n){
    pair<int,int>R={0,1};
    while(n>0){
        n/=10;
        R.first++;
        R.second*=10;
    }
    return R;
}

int solve(int w,int m,int k){
    auto p=cdpow10(m);
    int cd=p.first,lt=p.second,c=0;
    //cout<<cd<<' '<<lt<<endl;
    w/=k;
    while(w>0){
        int l=lt-m,cs=l*cd;
        if(w<cs)break;
        c+=l;
        w-=l*cd;
        m=lt;lt*=10;cd++;
    }
    c+=w/cd;
    return c;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CONSEQ.INP","r",stdin);freopen("CONSEQ.OUT","w",stdout);
    int w,m,k;cin>>w>>m>>k;
    cout<<solve(w,m,k);
    return 0;
}
