#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CLIMB.INP","r",stdin);freopen("CLIMB.OUT","w",stdout);
    int n;cin>>n;
    int A[n],f[n]={};//for(int i=0;i<n;i++)f[i]=0;
    for(int i=0;i<n;i++){
        cin>>A[i];
        if(i>0&&A[i]>A[i-1])f[i]=f[i-1]+A[i]-A[i-1];
    }
    cout<<*max_element(f,f+n);
    return 0;
}