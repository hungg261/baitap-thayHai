#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CITIES.INP","r",stdin);freopen("CITIES.OUT","w",stdout);
    int t;cin>>t;
    while(t--){
        int n,x1=INT_MIN,x2=INT_MAX,y1=INT_MIN,y2=INT_MAX;cin>>n;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            x1=max(x1,a);x2=min(x2,a);
            y1=max(y1,b);y2=min(y2,b);
        }
        long long r=max(x1-x2,y1-y2);
        cout<<r*r<<endl;
    }
    return 0;
}