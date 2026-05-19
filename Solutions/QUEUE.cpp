// BT_HungPhan_03102025
/******************************************************************************
Link: QUEUE
Code: QUEUE
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-28-23.42.05
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("QUEUE.INP","r",stdin);
    freopen("QUEUE.OUT","w",stdout);
    cin>>n>>m;

    int ans=0;
    while(n>=m){
        ans+=m;

        n-=m;
        if(n == 1){
            ++ans;
        }
        n/=2;
    }
    ans+=n;

    cout<<ans<<'\n';
    return 0;
}
