/******************************************************************************
Link: DISTRIBUTION
Code: DISTRIBUTION
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-10-21.23.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n,t[100005],P[100005];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i];
        P[i]=P[i-1]+t[i];
    }

    int target=(P[n]*2-1)/3+1;
    int l=1,h=n-1,res=1;
    while(l<=h){
        int mid=(l+h)/2;
        if(P[mid]<=target){
            res=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    cout<<res<<' '<<n-res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
//    freopen("DISTRIBUTION.INP","r",stdin);
//    freopen("DISTRIBUTION.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
