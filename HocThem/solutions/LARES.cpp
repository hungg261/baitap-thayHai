#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("LARES.INP","r",stdin);freopen("LARES.OUT","w",stdout);
    int m,n,k;cin>>m>>n>>k;
    cout<<min({m/2,n,(m+n-k)/3});
    return 0;
}
