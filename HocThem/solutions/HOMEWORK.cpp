#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("HOMEWORK.INP","r",stdin);freopen("HOMEWORK.OUT","w",stdout);
    int n,m,s=0,r=0;cin>>n>>m;
    int A[n];
    for(int&k:A){
        cin>>k;s+=k;
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        A[a-1]=0;
    }
    cout<<s-*max_element(A,A+n);
    return 0;
}
