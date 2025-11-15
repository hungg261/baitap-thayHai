#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

bool check(string&N,string&sn,int n,int g){
    for(int i=0;i<n;++i){
        if(N[i]!=sn[i%g])return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BASESTRING.INP","r",stdin);freopen("BASESTRING.OUT","w",stdout);
    string A,B;cin>>A>>B;
    int a=A.size(),b=B.size(),g=__gcd(a,b);
    string sa=A.substr(0,g),sb=B.substr(0,g);

    if(sa==sb&&check(A,sa,a,g)&&check(B,sb,b,g))cout<<sa;
    else cout<<"NO";
    return 0;
}
