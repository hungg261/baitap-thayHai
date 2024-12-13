#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int countdigits(int x){
    return (int)log10(x)+1;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SEQLEN.INP","r",stdin);freopen("SEQLEN.OUT","w",stdout);
    int n;cin>>n;
    int c=0,lt=1,cd=countdigits(n);
    for(int i=1;i<cd;i++){
        int d=9*lt;
        lt*=10;
        c+=d*i;
        n-=d;
    }
    c+=n*cd;
    cout<<c;
    return 0;
}