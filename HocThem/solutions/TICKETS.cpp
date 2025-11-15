#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TICKETS.INP","r",stdin);freopen("TICKETS.OUT","w",stdout);
    int n,k,p1,p2;cin>>n>>k>>p1>>p2;
    cout<<min(n/k*p2,n/k*k*p1)+min(n%k*p1,p2);
    return 0;
}