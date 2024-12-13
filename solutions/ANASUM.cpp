#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("ANASUM.INP","r",stdin);freopen("ANASUM.OUT","w",stdout);
    int n;cin>>n;
    int A[n];inp(A);
    sort(A,A+n);

    int r=1;
    for(int i=0;i<n&&A[i]<=r;++i){
        r+=A[i];
    }
    cout<<r;
    return 0;
}
