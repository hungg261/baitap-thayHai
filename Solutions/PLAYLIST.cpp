// BT_HungPhan_03102025
/******************************************************************************
Link: PLAYLIST
Code: PLAYLIST
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-23-20.18.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
int a[MAXN+5],n;

int temp[MAXN+5];
void compress(){
    for(int i=1;i<=n;++i)temp[i]=a[i];
    sort(temp+1,temp+n+1);

    for(int i=1;i<=n;++i){
        a[i]=lower_bound(temp+1,temp+n+1,a[i])-temp;
    }
}

int mark[MAXN+5];
void solve(){
    int ans=0;
    int i=1;
    for(int j=1;j<=n;++j){
        while(mark[a[j]]>0){
            --mark[a[i]];
            ++i;
        }
        ++mark[a[j]];

        ans=max(ans,j-i+1);
    }

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PLAYLIST.INP","r",stdin);
    freopen("PLAYLIST.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    compress();
    solve();
    return 0;
}
