// BT_HungPhan_03102025
/******************************************************************************
Link: BAGS
Code: BAGS
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-17-20.58.59
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=3e5;
int n,k;
struct jewelry{
    int m,v;
} a[MAX+5];
multiset<int>c;

int cmp(jewelry&e,jewelry&f){
    if(e.v==f.v){
        return e.m<f.m;
    }
    return e.v>f.v;
}

void solve(){
    int ans=0;
    for(int i=1;i<=n;++i){
        auto higher=c.lower_bound(a[i].m);
        if(higher!=c.end()){
            ans+=a[i].v;
            c.erase(higher);
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BAGS.INP","r",stdin);
    freopen("BAGS.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i].m>>a[i].v;
    }
    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=k;++i){
        int cur;
        cin>>cur;

        c.insert(cur);
    }

    solve();
    return 0;
}
