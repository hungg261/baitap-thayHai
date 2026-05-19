// BT_HungPhan_03102025
/******************************************************************************
Link: TREES
Code: TREES
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-05-20.43.05
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXK=1e5;
int a[MAXK+5],k,p;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TREES.INP","r",stdin);
    freopen("TREES.OUT","w",stdout);
    cin>>k>>p;
    for(int i=1;i<=k;++i){
        cin>>a[i];
    }

    sort(a+1,a+k+1);
    int ans=accumulate(a+1,a+(k-p+1)+1,0LL);

    for(int i=1;i<=p-1;++i){
        ans+=min(a[k-p+i+1],ans/i+1);
    }

    cout<<ans<<'\n';
    return 0;
}
