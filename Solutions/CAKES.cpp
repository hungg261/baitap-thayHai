// BT_HungPhan_03102025
/******************************************************************************
Link: CAKES
Code: CAKES
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-14-21.06.42
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
pair<int,int>a[MAXN+5];
int n,T;

priority_queue<pair<int,int>>pq;

void solve(){
    int total=0;
    int ans=0;

    a[0].first=0;
    int res=0;
    for(int i=1;i<=n;++i){
        pq.push({a[i].second,a[i].first});

        total+=a[i].first-a[i-1].first;
        total+=a[i].second;
        ++res;

        while(!pq.empty()&&total>T){
            total-=pq.top().first;
            pq.pop();

            --res;
        }

        ans=max(ans,res);
    }

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CAKES.INP","r",stdin);
    freopen("CAKES.OUT","w",stdout);
    cin>>n>>T;
    for(int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
    }

    solve();
    return 0;
}
