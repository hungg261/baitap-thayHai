#include <bits/stdc++.h>
#define int long long
using namespace std;

int fa[8]={0,103,193,73,163,43,133,13};
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FRIDAY.INP","r",stdin);freopen("FRIDAY.OUT","w",stdout);
    int n,k;cin>>n>>k;
    cout<<(30*n-fa[k]+210)/210;
    return 0;
}