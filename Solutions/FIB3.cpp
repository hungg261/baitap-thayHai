// 06032024
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FIB3.INP","r",stdin);freopen("FIB3.OUT","w",stdout);
    int t;cin>>t;
    while(t--){
        int a,b,n,c;cin>>a>>b>>n;
        int f[n+1];f[0]=a;f[1]=b;
        for(int i=2;i<=n;i++){
            f[i]=(f[i-1]%mod+f[i-2]%mod)%mod;
        }
        cout<<f[n]<<endl;;
    }
    return 0;
}