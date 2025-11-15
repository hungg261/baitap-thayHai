/******************************************************************************
Link: APPLES
Code: APPLES
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-13-19.45.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n,m,a,c[69];

bool in_range(int l,int r,int x){
    return l<=x&&x<=r;
}

void solve(){
    int low=1,high=m;
    int ans=0;
    for(int i=1;i<=a;++i){
        if(in_range(low,high,c[i]))continue;

        int dist_low=abs(c[i]-low),dist_high=abs(c[i]-high);
        if(dist_high<dist_low){
            ans+=dist_high;
            high=c[i];
            low=high-m+1;
        }
        else{
            ans+=dist_low;
            low=c[i];
            high=low+m-1;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("APPLES.INP","r",stdin);
    freopen("APPLES.OUT","w",stdout);
    cin>>n>>m>>a;
    for(int i=1;i<=a;++i){
        cin>>c[i];
    }

    solve();
    return 0;
}
