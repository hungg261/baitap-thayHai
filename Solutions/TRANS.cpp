#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TRANS.INP","r",stdin);freopen("TRANS.OUT","w",stdout);
    int n,a,b,c1=0,c2=0;cin>>n>>a>>b;
    while(n>0){
        if(ceil(n/50.0)*a>ceil(n/4.0)*b){
            n-=4;
            c2++;
        }
        else{
            n-=50;
            c1++;
        }
    }
    cout<<c1<<' '<<c2;
    return 0;
}