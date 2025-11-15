#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    int n;
    cin>>n;
    
    int a=ceil(sqrt(n));
    if((a-1)*a>=n)cout<<(a-1)<<' '<<a<<'\n';
    else cout<<a<<' '<<a<<'\n';
    return 0;
}
