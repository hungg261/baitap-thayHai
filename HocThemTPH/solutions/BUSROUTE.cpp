#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BUSROUTE.INP","r",stdin);freopen("BUSROUTE.OUT","w",stdout);
    int a,b,n,r=INT_MAX;cin>>a>>b>>n;
    while(n--){
        int c,m;cin>>c>>m;
        bool f=0;
        for(int i=0;i<m;i++){
            int k;cin>>k;
            if(!f&&k==a)f=1;
            if(f&&k==b)r=min(r,c);
        }
    }
    cout<<(r==INT_MAX?-1:r);
    return 0;
}