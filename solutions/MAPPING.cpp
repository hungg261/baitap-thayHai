#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MAPPING.INP","r",stdin);freopen("MAPPING.OUT","w",stdout);
    int x,y,z;cin>>x>>y>>z;
    int a=ceil((sqrt(8*z+1)-1)/2.0),b=a*(a+1)/2;
    cout<<(-3*x-y+(x+y)*(x+y))/2+1<<'\n'<<b-z+1<<' '<<a-b+z;
    return 0;
}
