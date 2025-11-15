#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MAEXP.INP","r",stdin);freopen("MAEXP.OUT","w",stdout);
    int n,s=0,r=0;cin>>n;
    int A[n];for(int&k:A){cin>>k;s+=k;};
    for(int i=0;i<n-2;i++){
        r=max(r,s+A[i]*A[i+1]*A[i+2]-A[i]-A[i+1]-A[i+2]);
        for(int j=i+2;j<n-1;j++){
            r=max(r,s+A[i]*A[i+1]+A[j]*A[j+1]-A[i]-A[i+1]-A[j]-A[j+1]);
            //cout<<A[i]<<':'<<A[j]<<'='<<r<<endl;
        }
    }
    cout<<r;
    return 0;
}
